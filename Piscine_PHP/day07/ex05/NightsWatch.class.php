<?php

	class NightsWatch implements IFighter {

		private $_fight;

		public function recruit ($man) {

			if ($man instanceof IFighter) {
				$_fight .= $man->fight();
			}
		}

		public function fight() {
			print($_fight);
		}
	}
?>