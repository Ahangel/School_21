#!/usr/bin/php
<?php
	if ($argc > 1) {
		$i = 1;
		while($i < $argc) {
			$string .= " ".$argv[$i]." ";
			$i++;
		}
		$temp = trim($string);
		while ((strpos($temp, "  ")) == true)
			$temp = str_replace("  ", " ", $temp);
		$tab = explode(" ", $temp);
		sort($tab);
		foreach ($tab as $elem)
			echo "$elem\n";
	}
?>
