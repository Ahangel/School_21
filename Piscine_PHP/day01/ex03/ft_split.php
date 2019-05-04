#!/usr/bin/php
<?php
	function ft_split($string) {
		if ($string == NULL) {
			echo "Empty input in function ft_split!\n";
			exit();
		}
		$string = trim($string);
		$temp = explode(" ", $string);
		$temp = array_filter($temp, "strlen");
		sort($temp);
		return($temp);
	}
?>
