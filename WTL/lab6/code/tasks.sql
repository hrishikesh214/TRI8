CREATE TABLE `tasks` (
  `id` int(11) NOT NULL,
  `action` varchar(50) NOT NULL,
  `description` text NOT NULL,
  `remind_at` datetime NOT NULL
) ;