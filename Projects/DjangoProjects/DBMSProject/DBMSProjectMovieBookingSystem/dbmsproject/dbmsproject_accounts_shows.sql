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
-- Table structure for table `accounts_shows`
--

DROP TABLE IF EXISTS `accounts_shows`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `accounts_shows` (
  `shows` int NOT NULL AUTO_INCREMENT,
  `time` varchar(100) NOT NULL,
  `date` varchar(15) NOT NULL,
  `price` int NOT NULL,
  `cinema_id` int NOT NULL,
  `movie_id` int NOT NULL,
  PRIMARY KEY (`shows`),
  KEY `accounts_shows_cinema_id_a9c57c57_fk_accounts_cinema_cinema` (`cinema_id`),
  KEY `accounts_shows_movie_id_68d70362_fk_accounts_movie_movie` (`movie_id`),
  CONSTRAINT `accounts_shows_cinema_id_a9c57c57_fk_accounts_cinema_cinema` FOREIGN KEY (`cinema_id`) REFERENCES `accounts_cinema` (`cinema`),
  CONSTRAINT `accounts_shows_movie_id_68d70362_fk_accounts_movie_movie` FOREIGN KEY (`movie_id`) REFERENCES `accounts_movie` (`movie`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `accounts_shows`
--

LOCK TABLES `accounts_shows` WRITE;
/*!40000 ALTER TABLE `accounts_shows` DISABLE KEYS */;
INSERT INTO `accounts_shows` VALUES (1,'20:30','2021-12-11',700,1,2),(2,'21:38','2021-12-10',650,1,2),(3,'18:25','2021-12-10',750,1,4),(4,'16:50','2021-12-09',700,1,6),(5,'09:25','2021-12-12',500,1,5),(6,'14:00','2021-12-16',950,1,3),(7,'18:30','2021-12-09',800,1,1),(8,'16:30','2021-12-10',670,2,1),(9,'10:00','2021-12-12',630,2,2),(10,'18:25','2021-12-13',740,2,3),(11,'20:00','2021-12-10',600,2,7),(12,'17:30','2021-12-15',800,2,4),(13,'18:30','2021-12-11',800,2,2),(14,'17:40','2021-12-10',750,2,2),(15,'15:40','2021-12-10',530,3,4),(16,'18:35','2021-12-11',560,3,4),(17,'21:30','2021-12-13',650,3,2),(18,'18:40','2021-12-13',660,3,2),(19,'07:30','2021-12-10',690,3,5),(20,'18:30','2021-12-10',750,3,7);
/*!40000 ALTER TABLE `accounts_shows` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-12-08 22:41:39
