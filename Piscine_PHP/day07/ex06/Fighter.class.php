<?php
	class Fighter {

		private $name;

		public function __construct($str) {

			if ($str) {
				$this->name = $str;
			} else {
				$this->name = NULL;
			}
		}

		public function __toString() {

			if ($this->name) {
				return($this->name);
			}
		}
	}
?>