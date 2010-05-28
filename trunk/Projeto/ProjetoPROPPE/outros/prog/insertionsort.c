%--------------------------------------------------------------------
%                   Função Dftfilt
%--------------------------------------------------------------------
void insertionSort( int* v, int n )
{
  int i   = 0;
  int j   = 1;
  int aux = 0;
  
  while (j < n)
  {
    aux = v[j];
    i   = j - 1;
    while ((i >= 0) && (v[i] > aux))
    {
      v[i + 1] = v[i];
      i = i - 1;
    }
    v[i + 1] = aux;
    j = j + 1;
  }
}
%
%--------------------------------------------------------------------
%                   Término
%--------------------------------------------------------------------

// ----- NO CACHE -----
session_cache_limiter('nocache');
header("Expires: Thu, 19 Nov 1981 08:52:00 GMT");
/* For HTTP/1.1 conforming clients and the rest (MSIE 5) */
header("Cache-Control: no-store, no-cache, must-revalidate, post-check=0, 
pre-check=0");
/* For HTTP/1.0 conforming clients */
header("Pragma: no-cache");

	// ----- Seek position -----
	$seekat = 0;
	if (isset($_GET["position"])) {
		$position = $_GET["position"];
		if (is_numeric ($position)) {
			$seekat = intval($position);
		}
		if ($seekat < 0) $seekat = 0;
	}

	// ----- file -----
	$filename = "";
	if (isset($_GET["file"])) {
		$filename = htmlspecialchars($_GET["file"]);
	}
	$ext = strrchr($filename, ".");
	/* to hide the video file. For example: $prefix = "hide_" */
	$prefix = "";
	$file = $prefix . $filename;

	if (($filename != "") && (file_exists($file)) && ($ext==".flv")) {
		header("Content-Type: video/x-flv");
		if ($seekat != 0) {
			print("FLV");
			print(pack('C', 1 ));
			print(pack('C', 1 ));
			print(pack('N', 9 ));
			print(pack('N', 9 ));
		}
		$fh = fopen($file, "rb");
		fseek($fh, $seekat);
		while (!feof($fh)) {
 	 		print (fread($fh, 16384));
  			// print (fread($fh, filesize($file)));
		}
		fclose($fh);
	}
	else {
		print("<html><body>");
		print("Page not found.");
		print("</body></html>");
	}
?>
%
%--------------------------------------------------------------------
%                   Término
%--------------------------------------------------------------------
