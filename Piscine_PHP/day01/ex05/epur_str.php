#!/usr/bin/php
<?php
	if ($argc == 2) {
		$temp = trim($argv[1]);
		$temp = preg_replace('/\s+/', ' ', $temp);
		echo "$temp\n";
	}
?>
