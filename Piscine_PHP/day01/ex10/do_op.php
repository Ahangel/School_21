#!/usr/bin/php
<?php
	if ($argc != 4)
		echo "Incorrect parameters\n";
	else {
		if (strpos($argv[2], "+") !== false)
			echo ($argv[1] + $argv[3])."\n";
		else if (strpos($argv[2], "-") !== false)
			echo ($argv[1] - $argv[3])."\n";
		else if (strpos($argv[2], "*") !== false)
			echo ($argv[1] * $argv[3])."\n";
		else if (strpos($argv[2], "/") !== false)
			echo ($argv[1] / $argv[3])."\n";
		else if (strpos($argv[2], "%") !== false)
			echo ($argv[1] % $argv[3])."\n";
	}
?>
