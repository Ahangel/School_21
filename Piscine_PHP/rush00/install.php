<?php
	include 'functions.php';

	if (file_exists("private") == FALSE)
		mkdir("private");
	if (!file_exists("private/database.csv"))
	{
		add_article("Burger + Frites + Drink", "5.60", array("Home", "Combo"), "http://i.imgur.com/0TyqtoU.png");
		add_article("American Sandwich + Frites", "3.50", array("Home", "Combo"), "http://yummydelicious.com/cdin.us/01pics/ydf/sandwich.jpg");
		add_article("sandwich with tuna", "2.50", array("Home", "Sandwiches"), "https://www.fcw.su/upload/blogs/2ce871b86fb197a90548d1808b9d0141.jpg.jpg");
		add_article("sandwich with turkey", "2.50", array("Home", "Sandwiches"), "http://f.vkusnota.kz/resized/recipes/019/209/sendvich_s_indeykoy_i_sirom_bry1.jpg.500x500.jpg");
		add_article("sandwich with salmon", "2.50", array("Home", "Sandwiches"), "https://s1.eda.ru/StaticContent/Photos/130104145234/150118212036/p_O.jpg");
		add_article("bagel with chicken", "3.00", array("Home", "Sandwiches"), "https://media-cdn.tripadvisor.com/media/photo-s/09/98/2b/a3/bellini.jpg");
		add_article("toast with jam and chicken", "3.20", array("Home", "Sandwiches"), "https://avatars.mds.yandex.net/get-zen_doc/1108934/pub_5c112714c1111f00ab051905_5c112732aace0400adfd7c33/scale_2400");
	}
	if (!user_exists("root"))
		create_user("root", "root", "root");
	if (!user_exists("guest"))
		create_user("guest", "", "guest");
	if (!user_exists("root"))
		create_user("admin", "admin", "admin");
?>
