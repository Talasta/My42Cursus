-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Apr 01, 2018 at 12:00 PM
-- Server version: 5.7.21
-- PHP Version: 7.1.15

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `shop`
--
CREATE DATABASE IF NOT EXISTS `shop` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `shop`;

-- --------------------------------------------------------

--
-- Table structure for table `category`
--

CREATE TABLE IF NOT EXISTS `category` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `category`
--

INSERT INTO `category` (`ID`, `name`) VALUES
(3, 'Clous'),
(4, 'Vis'),
(5, 'Vis plate'),
(6, 'Vis cruciforme'),
(7, 'Outillage'),
(8, 'Materiel'),
(9, 'Tourne vis');

-- --------------------------------------------------------

--
-- Table structure for table `panier`
--

CREATE TABLE IF NOT EXISTS `panier` (
  `ID_user` int(11) NOT NULL,
  `ID_product` int(11) NOT NULL,
  `count` int(11) NOT NULL,
  `status` int(11) NOT NULL,
  KEY `ID_user` (`ID_user`),
  KEY `ID_product` (`ID_product`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `panier`
--

INSERT INTO `panier` (`ID_user`, `ID_product`, `count`, `status`) VALUES
(15, 7, 1, 0),
(15, 8, 1, 0),
(15, 9, 1, 0),
(15, 10, 1, 0),
(15, 11, 1, 0),
(15, 12, 1, 0),
(15, 13, 2, 0),
(15, 14, 3, 0),
(15, 21, 2, 0),
(15, 20, 1, 0),
(15, 19, 1, 0),
(15, 18, 1, 0),
(15, 16, 1, 0),
(15, 25, 2, 0),
(15, 26, 1, 0),
(15, 27, 1, 0),
(15, 23, 1, 0),
(15, 22, 1, 0);

-- --------------------------------------------------------

--
-- Table structure for table `product`
--

CREATE TABLE IF NOT EXISTS `product` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `price` float NOT NULL,
  `desq` text,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=29 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `product`
--

INSERT INTO `product` (`ID`, `name`, `price`, `desq`) VALUES
(7, 'clou 0.1', 0.05, ''),
(8, 'clou 0.2', 0.07, ''),
(9, 'clou 0.5', 0.15, ''),
(10, 'clou 0.8', 0.2, ''),
(11, 'clou 1.0', 0.25, ''),
(12, 'clou 1.5', 0.4, ''),
(13, 'clou 3.0', 1, ''),
(14, 'vis cruciforme 0.1', 0.1, ''),
(15, 'vis cruciforme 0.5', 0.4, ''),
(16, 'vis cruciforme 1.2', 0.7, ''),
(17, 'vis plate 0.3', 0.2, ''),
(18, 'vis plate 0.8', 0.5, ''),
(19, 'vis plate 1.2', 0.7, ''),
(20, 'marteau', 15.99, ''),
(21, 'tourne vis plat taille M', 7.59, ''),
(22, 'tourne vis plat taille L', 10.99, ''),
(23, 'tourne vis plat taille XL', 12.99, ''),
(24, 'tourne vis cruciforme (Ref: 45)', 6.39, ''),
(25, 'tourne vis cruciforme (Ref: 45/56)', 9.59, ''),
(26, 'tabouret d\'atelier', 109.99, ''),
(27, 'perceuse (Ref 21/90)', 159.99, ''),
(28, 'perceuse a recharge', 56.49, '');

-- --------------------------------------------------------

--
-- Table structure for table `product_category`
--

CREATE TABLE IF NOT EXISTS `product_category` (
  `ID_product` int(11) NOT NULL,
  `ID_category` int(11) NOT NULL,
  KEY `ID_product` (`ID_product`),
  KEY `ID_category` (`ID_category`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `product_category`
--

INSERT INTO `product_category` (`ID_product`, `ID_category`) VALUES
(7, 3),
(8, 3),
(9, 3),
(10, 3),
(11, 3),
(12, 3),
(13, 3),
(14, 4),
(15, 4),
(16, 4),
(17, 4),
(18, 4),
(19, 4),
(17, 5),
(18, 5),
(19, 5),
(14, 6),
(15, 6),
(16, 6),
(20, 7),
(21, 7),
(22, 7),
(23, 7),
(24, 7),
(25, 7),
(27, 7),
(28, 7),
(26, 8),
(21, 9),
(22, 9),
(23, 9),
(24, 9),
(25, 9);

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE IF NOT EXISTS `user` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(255) NOT NULL,
  `passwd` varchar(255) NOT NULL,
  `admin` tinyint(1) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`ID`, `login`, `passwd`, `admin`) VALUES
(15, 'root', '63a9f0ea7bb98050796b649e85481845', 1),
(17, 'gerard', '415152a5b8a5ffd9e358c1bce69624ed', 0),
(18, 'maxime', '21232f297a57a5a743894a0e4a801fc3', 1),
(19, 'clement', '21232f297a57a5a743894a0e4a801fc3', 0);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `panier`
--
ALTER TABLE `panier`
  ADD CONSTRAINT `panier_ibfk_1` FOREIGN KEY (`ID_user`) REFERENCES `user` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `panier_ibfk_2` FOREIGN KEY (`ID_product`) REFERENCES `product` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `product_category`
--
ALTER TABLE `product_category`
  ADD CONSTRAINT `product_category_ibfk_1` FOREIGN KEY (`ID_product`) REFERENCES `product` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `product_category_ibfk_2` FOREIGN KEY (`ID_category`) REFERENCES `category` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
