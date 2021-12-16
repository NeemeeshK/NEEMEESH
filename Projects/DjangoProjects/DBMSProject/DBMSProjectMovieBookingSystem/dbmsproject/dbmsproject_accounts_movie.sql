-- MySQL dump 10.13  Distrib 8.0.27, for Win64 (x86_64)
--
-- Host: localhost    Database: dbmsproject
-- ------------------------------------------------------
-- Server version	8.0.27

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `accounts_movie`
--

DROP TABLE IF EXISTS `accounts_movie`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `accounts_movie` (
  `movie` int NOT NULL AUTO_INCREMENT,
  `movie_name` varchar(50) NOT NULL,
  `movie_trailer` varchar(300) NOT NULL,
  `movie_rdate` varchar(20) NOT NULL,
  `movie_des` longtext NOT NULL,
  `movie_rating` decimal(3,1) NOT NULL,
  `movie_poster` varchar(100) NOT NULL,
  `movie_genre` varchar(50) NOT NULL,
  `movie_duration` varchar(10) NOT NULL,
  PRIMARY KEY (`movie`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `accounts_movie`
--

LOCK TABLES `accounts_movie` WRITE;
/*!40000 ALTER TABLE `accounts_movie` DISABLE KEYS */;
INSERT INTO `accounts_movie` VALUES (1,'Spider Man - No Way Home','https://www.youtube.com/watch?v=JfVOs4VSpmA','16-12-2021','For the first time in the cinematic history of Spider-Man, our friendly neighborhood hero\'s identity is revealed, bringing his Super Hero responsibilities into conflict with his normal life and putting those he cares about most at risk. When he enlists Doctor Strange’s help to restore his secret, the spell tears a hole in their world, releasing the most powerful villains who’ve ever fought a Spider-Man in any universe. Now, Peter will have to overcome his greatest challenge yet, which will not only forever alter his own future but the future of the Multiverse.',9.0,'movies/poster/2Q.png','Action | Comedy | Romance','2hr 00min'),(2,'Sooryavanshi','https://www.youtube.com/watch?v=u5r77-OQwa8','5-11-2021','Sooryavanshi traces the acts and serious antics of DCP Veer Sooryavanshi, the chief of the Anti-Terrorism Squad in India.',8.7,'movies/poster/soryavanshi-app-780c98c0-36fd-11ec-b83e-0f984fa97b41.png','Action | Comedy','2hr 39min'),(3,'Baahubali- The Conclusion','https://www.youtube.com/watch?v=G62HrubdD6o','28-04-2017','When Shiva, the son of Bahubali, learns about his heritage, he begins to look for answers. His story is juxtaposed with past events that unfolded in the Mahishmati Kingdom.',9.8,'movies/poster/3444_Prabhas.png','Action | Comedy | Romance | Thriller','3hr 10min'),(4,'Satyamev Jayate -2','https://www.youtube.com/watch?v=e6VZiwlzhSw','26-11-2021','Satyameva Jayate 2 is a 2021 Indian Hindi-language vigilante action film written and directed by Milap Zaveri with production by T-Series and Emmay Entertainment.[4] Based on the fight against injustice and misuse of power, it is an official spiritual sequel of the 2018 film Satyameva Jayate and stars John Abraham in a triple role alongside Divya Khosla Kumar, Rajeev Pillai and Anup Soni in important characters.[5] The release date was postponed due to rise in COVID-19 cases.[6] The film released on 25 November 2021.[1]',8.4,'movies/poster/WhatsApp-Image-2021-03-17-at-10.png','Action | Comedy','2hr 50min'),(5,'F9','https://www.youtube.com/watch?v=RMmLTmjXKH8','25-06-2021','Dom and the crew must take on an international terrorist who turns out to be Dom and Mia\'s estranged brother.',8.9,'movies/poster/maxresdefault.png','Action | Racing','2hr 5min'),(6,'Mimi','https://youtu.be/_sc3HyeNxPs','30-07-2021','Experience the most unexpected journey with Mimi, it will leave you and your family in splits because it is nothing like what you are expecting!',8.7,'movies/poster/mimi.jpg','Comedy | Romance','2hr 25min'),(7,'Jolly LLB-2','https://youtu.be/uhiWdRBwSQo','10-02-2017','It is the year 2016, Jagdishwar \"Jolly\" Mishra (Akshay Kumar) is a Lucknow based lawyer, who stays with his wife Pushpa (Huma Qureshi) and son. Despite being a lawyer, he works as a menial assistant to one of the most famous lawyers of Lucknow, Mr. Rizvi, for whom his father had worked as an assistant for 30 years. He is street smart and dreams of his own law practice. To arrange money for his own chamber, Jolly lies to a widow, Hina Qasim, telling her that Mr. Rizvi will take her case and that the fee is 200,000 rupees. When Hina finds out that she had been lied to by Jolly, she commits suicide. Jolly soon discovers that Hina\'s husband Iqbal Qasim was killed in a fake encounter on 13 August 2015, the very next day of their marriage by Inspector Suryaveer Singh, who depicted him as Mohammed Iqbal Quadri, a terrorist in official documents. Singh also shot a fellow constable, Bhadouria, in order to show the encounter as genuine, leading to his death.',9.2,'movies/poster/th.jpg','Action | Comedy','2hr 30min');
/*!40000 ALTER TABLE `accounts_movie` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-12-08 22:41:40
