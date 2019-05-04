#!/usr/bin/php
<?php
	if ($argc > 1) {
		$temp = $argv[1];
		while ((strpos($temp, "  ")) == true)
			$temp = str_replace("  ", " ", $temp);
		$tab = explode(" ", $temp);
		$word_counter = count($tab);

		$i = 1;
		while ($i < $word_counter)
			echo $tab[$i++]." ";
		echo $tab[0]."\n";
	}
?>
