#!/usr/bin/php
<?php
	$nb = preg_match("/t[oi]t[oi]/", "toto");

	echo "$nb\n";

	$fd = fopen("data.csv", "r");

	while ($line = fgetcsv($fd, 0, ";")) {
		echo "$line";
	}

	fclose($fd);

	foreach ($tab as $elem) {
		echo "$elem";
	}
?>
