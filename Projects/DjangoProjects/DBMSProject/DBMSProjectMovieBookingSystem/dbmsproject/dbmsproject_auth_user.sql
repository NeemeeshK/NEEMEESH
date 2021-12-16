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
-- Table structure for table `auth_user`
--

DROP TABLE IF EXISTS `auth_user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `auth_user` (
  `id` int NOT NULL AUTO_INCREMENT,
  `password` varchar(128) NOT NULL,
  `last_login` datetime(6) DEFAULT NULL,
  `is_superuser` tinyint(1) NOT NULL,
  `username` varchar(150) NOT NULL,
  `first_name` varchar(150) NOT NULL,
  `last_name` varchar(150) NOT NULL,
  `email` varchar(254) NOT NULL,
  `is_staff` tinyint(1) NOT NULL,
  `is_active` tinyint(1) NOT NULL,
  `date_joined` datetime(6) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_user`
--

LOCK TABLES `auth_user` WRITE;
/*!40000 ALTER TABLE `auth_user` DISABLE KEYS */;
INSERT INTO `auth_user` VALUES (1,'pbkdf2_sha256$260000$9pBwdnmhrE2Oh3aF0ERIqg$wtoeg/0rvWhnF0kBFIHfhSds8mPTXRsZZRxmRwFQefQ=','2021-12-08 15:04:22.797067',1,'Admin','','','admin@gmail.com',1,1,'2021-12-08 14:52:25.303773'),(2,'pbkdf2_sha256$260000$RlgJsT7o8Z5nMj7V3Ga1uJ$rk7A5qUyurtZpu4/92fMX29neeZAhw6NjM26L3o9o64=','2021-12-08 16:41:08.972045',0,'neemeesh','Neemeesh','Khanzode','neemeesh.22010929@viit.ac.in',0,1,'2021-12-08 14:57:13.251586'),(3,'pbkdf2_sha256$260000$otoOK1i7DCK4BmRc0j4SjY$kLk68kIY1FbDRtTtRn06OZAw6EVhQh9U6WqAjLqzlkQ=','2021-12-08 16:43:16.747359',0,'jyotirmay','Jyotirmay','Khavasi','jyotirmay.22010699@viit.ac.in',0,1,'2021-12-08 14:58:28.150805'),(4,'pbkdf2_sha256$260000$Qrj0TK74F3Dvn9N7iRaaWa$NsQlmUlWEh7MK1QxMHARLzKknAc4zqAo9lJy2cTDrsI=','2021-12-08 16:48:40.344721',0,'suraj','Suraj','Raskar','suraj.22010472@viit.ac.in',0,1,'2021-12-08 14:59:08.050201'),(5,'pbkdf2_sha256$260000$dRxAZMkf9vhPBRJlg826af$nraUu09hip4c9dN2ArZZnYt/nd73OZ3t1m7UtQsYsbw=','2021-12-08 16:44:17.185883',0,'shardul','Shardul','Khandebharad','shardul.22010207@viit.ac.in',0,1,'2021-12-08 14:59:48.232820'),(6,'pbkdf2_sha256$260000$pGXoDUX7CqzgmS7h1aD7aZ$CLU/ejkJOddqiQODT6Gske8TtZH3KjcsVcyzFK0QApA=','2021-12-08 16:04:35.257743',0,'imax','imax','imax','imax@gmail.com',0,1,'2021-12-08 15:01:29.915435'),(7,'pbkdf2_sha256$260000$TwFRdTa8SULedC8Ex5xZPf$ZkHdc+BsyI8kIYPZCUW64LAr2P9IIZ8GUC8SF0Enxe4=','2021-12-08 16:18:52.381914',0,'pvr','PVR','PVR','pvr@gmail.com',0,1,'2021-12-08 15:02:35.772488'),(8,'pbkdf2_sha256$260000$myjGnhmRv5jlNirL1iTvRr$IGuGm+57gomrFO//9qCOsBaGDunJyQ8FHzSHa4EHQpQ=','2021-12-08 16:33:47.326518',0,'viit','VIIT','VIIT','viit@gmail.com',0,1,'2021-12-08 15:03:46.933965');
/*!40000 ALTER TABLE `auth_user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-12-08 22:41:41
