/*
Navicat MySQL Data Transfer

Source Server         : gm
Source Server Version : 50721
Source Host           : localhost:3306
Source Database       : mysms

Target Server Type    : MYSQL
Target Server Version : 50721
File Encoding         : 65001

Date: 2018-06-24 08:16:28
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for classinfo
-- ----------------------------
DROP TABLE IF EXISTS `classinfo`;
CREATE TABLE `classinfo` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) NOT NULL,
  `Num` int(11) NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of classinfo
-- ----------------------------
INSERT INTO `classinfo` VALUES ('1', '一年1班', '50');
INSERT INTO `classinfo` VALUES ('2', '一年2班', '60');
INSERT INTO `classinfo` VALUES ('3', '二年1班', '47');
INSERT INTO `classinfo` VALUES ('6', '二年2班', '38');

-- ----------------------------
-- Table structure for functioninfo
-- ----------------------------
DROP TABLE IF EXISTS `functioninfo`;
CREATE TABLE `functioninfo` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `Code` varchar(255) NOT NULL,
  `Name` varchar(255) NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=24 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of functioninfo
-- ----------------------------
INSERT INTO `functioninfo` VALUES ('1', 'UserManage', '用户管理');
INSERT INTO `functioninfo` VALUES ('2', 'ClassAdd', '增加班级');
INSERT INTO `functioninfo` VALUES ('3', 'ClassDel', '删除班级');
INSERT INTO `functioninfo` VALUES ('4', 'ClassSearch', '查找班级');
INSERT INTO `functioninfo` VALUES ('5', 'ClassModify', '修改班级');
INSERT INTO `functioninfo` VALUES ('6', 'StuAdd', '增加学生');
INSERT INTO `functioninfo` VALUES ('7', 'StuDel', '删除学生');
INSERT INTO `functioninfo` VALUES ('8', 'StuSearch', '查找学生');
INSERT INTO `functioninfo` VALUES ('9', 'StuModify', '修改学生');
INSERT INTO `functioninfo` VALUES ('10', 'LessonAdd', '增加课程');
INSERT INTO `functioninfo` VALUES ('11', 'LessonDel', '删除课程');
INSERT INTO `functioninfo` VALUES ('12', 'LessonSearch', '查找课程');
INSERT INTO `functioninfo` VALUES ('13', 'LessonModify', '修改课程');
INSERT INTO `functioninfo` VALUES ('14', 'ScoreAdd', '增加成绩');
INSERT INTO `functioninfo` VALUES ('15', 'ScoreDel', '删除成绩');
INSERT INTO `functioninfo` VALUES ('16', 'ScoreSearch', '查找成绩');
INSERT INTO `functioninfo` VALUES ('17', 'ScoreModify', '修改成绩');

-- ----------------------------
-- Table structure for lessoninfo
-- ----------------------------
DROP TABLE IF EXISTS `lessoninfo`;
CREATE TABLE `lessoninfo` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `Code` varchar(255) NOT NULL,
  `Name` varchar(255) NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of lessoninfo
-- ----------------------------
INSERT INTO `lessoninfo` VALUES ('1', '001818', '安卓');
INSERT INTO `lessoninfo` VALUES ('2', '002200', 'Java');
INSERT INTO `lessoninfo` VALUES ('3', '152058', 'C#');

-- ----------------------------
-- Table structure for roleinfo
-- ----------------------------
DROP TABLE IF EXISTS `roleinfo`;
CREATE TABLE `roleinfo` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of roleinfo
-- ----------------------------
INSERT INTO `roleinfo` VALUES ('1', '用户管理');
INSERT INTO `roleinfo` VALUES ('2', '班级管理');
INSERT INTO `roleinfo` VALUES ('3', '班级浏览');
INSERT INTO `roleinfo` VALUES ('4', '学生管理');
INSERT INTO `roleinfo` VALUES ('5', '学生浏览');
INSERT INTO `roleinfo` VALUES ('6', '课程管理');
INSERT INTO `roleinfo` VALUES ('7', '课程浏览');
INSERT INTO `roleinfo` VALUES ('8', '成绩管理');
INSERT INTO `roleinfo` VALUES ('9', '成绩浏览');

-- ----------------------------
-- Table structure for role_function
-- ----------------------------
DROP TABLE IF EXISTS `role_function`;
CREATE TABLE `role_function` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `RoleInfoId` int(11) NOT NULL,
  `FunctionInfoId` int(11) NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=38 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of role_function
-- ----------------------------
INSERT INTO `role_function` VALUES ('1', '1', '1');
INSERT INTO `role_function` VALUES ('2', '1', '2');
INSERT INTO `role_function` VALUES ('3', '1', '3');
INSERT INTO `role_function` VALUES ('4', '1', '4');
INSERT INTO `role_function` VALUES ('5', '1', '5');
INSERT INTO `role_function` VALUES ('6', '1', '6');
INSERT INTO `role_function` VALUES ('7', '1', '7');
INSERT INTO `role_function` VALUES ('8', '1', '8');
INSERT INTO `role_function` VALUES ('9', '1', '9');
INSERT INTO `role_function` VALUES ('10', '1', '10');
INSERT INTO `role_function` VALUES ('11', '1', '11');
INSERT INTO `role_function` VALUES ('12', '1', '12');
INSERT INTO `role_function` VALUES ('13', '1', '13');
INSERT INTO `role_function` VALUES ('14', '1', '14');
INSERT INTO `role_function` VALUES ('15', '1', '15');
INSERT INTO `role_function` VALUES ('16', '1', '16');
INSERT INTO `role_function` VALUES ('17', '1', '17');
INSERT INTO `role_function` VALUES ('18', '2', '2');
INSERT INTO `role_function` VALUES ('19', '2', '3');
INSERT INTO `role_function` VALUES ('20', '2', '4');
INSERT INTO `role_function` VALUES ('21', '2', '5');
INSERT INTO `role_function` VALUES ('22', '3', '4');
INSERT INTO `role_function` VALUES ('23', '4', '6');
INSERT INTO `role_function` VALUES ('24', '4', '7');
INSERT INTO `role_function` VALUES ('25', '4', '8');
INSERT INTO `role_function` VALUES ('26', '4', '9');
INSERT INTO `role_function` VALUES ('27', '5', '8');
INSERT INTO `role_function` VALUES ('28', '6', '10');
INSERT INTO `role_function` VALUES ('29', '6', '11');
INSERT INTO `role_function` VALUES ('30', '6', '12');
INSERT INTO `role_function` VALUES ('31', '6', '13');
INSERT INTO `role_function` VALUES ('32', '7', '12');
INSERT INTO `role_function` VALUES ('33', '8', '14');
INSERT INTO `role_function` VALUES ('34', '8', '15');
INSERT INTO `role_function` VALUES ('35', '8', '16');
INSERT INTO `role_function` VALUES ('36', '8', '17');
INSERT INTO `role_function` VALUES ('37', '9', '16');

-- ----------------------------
-- Table structure for scoreinfo
-- ----------------------------
DROP TABLE IF EXISTS `scoreinfo`;
CREATE TABLE `scoreinfo` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `StuId` int(11) NOT NULL,
  `LessonId` int(11) NOT NULL,
  `Score` double DEFAULT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of scoreinfo
-- ----------------------------
INSERT INTO `scoreinfo` VALUES ('1', '1', '1', '90');
INSERT INTO `scoreinfo` VALUES ('2', '1', '2', '85');
INSERT INTO `scoreinfo` VALUES ('3', '2', '1', '60');
INSERT INTO `scoreinfo` VALUES ('4', '2', '3', '85.3');

-- ----------------------------
-- Table structure for stuinfo
-- ----------------------------
DROP TABLE IF EXISTS `stuinfo`;
CREATE TABLE `stuinfo` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `No` varchar(255) NOT NULL,
  `Name` varchar(255) NOT NULL,
  `Class` varchar(255) NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of stuinfo
-- ----------------------------
INSERT INTO `stuinfo` VALUES ('1', '20180001', '刘一', '一年1班');
INSERT INTO `stuinfo` VALUES ('2', '20180002', '陈二', '一年1班');
INSERT INTO `stuinfo` VALUES ('3', '20180003', '张三', '二年2班');

-- ----------------------------
-- Table structure for userinfo
-- ----------------------------
DROP TABLE IF EXISTS `userinfo`;
CREATE TABLE `userinfo` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `UserName` varchar(255) NOT NULL,
  `Password` varchar(255) NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=28 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of userinfo
-- ----------------------------
INSERT INTO `userinfo` VALUES ('1', 'admin', '123');
INSERT INTO `userinfo` VALUES ('2', 'gm', '123');
INSERT INTO `userinfo` VALUES ('3', 'sb', '666');
INSERT INTO `userinfo` VALUES ('12', 'zz', '666');

-- ----------------------------
-- Table structure for user_role
-- ----------------------------
DROP TABLE IF EXISTS `user_role`;
CREATE TABLE `user_role` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `UserInfoId` int(11) NOT NULL,
  `RoleInfoId` int(11) NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of user_role
-- ----------------------------
INSERT INTO `user_role` VALUES ('1', '1', '1');
INSERT INTO `user_role` VALUES ('2', '2', '2');
INSERT INTO `user_role` VALUES ('3', '3', '3');
INSERT INTO `user_role` VALUES ('4', '4', '4');
