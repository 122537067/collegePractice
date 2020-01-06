
# 项目简介：
项目采用 SSM（Spring + Spring MVC + MyBatis）框架 + jQuery 来开发一个人事管理系统，让我们能够通过实际项目掌握 SSM 项目的开发。
在开始本项目前，务必已经掌握 Spring, Spring MVC, MyBatis, jQuery, javaScript 以及 html 等方面的基础知识。
本人事管理系统主要包括如下几个模块：

系统管理

部门管理

职位管理

员工管理

公告管理

# 整个系统包含上述的几个模块，每个模块又包括多个功能：

系统管理：添加管理员、删除管理员、修改管理员和查询管理员（全部查询和按用户名模糊查询）

部门管理：添加部门、删除部门、修改部门和查询部门（全部查询和按部门名称模糊查询）

职位管理：添加职位、删除职位、修改职位和查询职位（全部查询和按职位名称模糊查询）

员工管理：添加员工、删除员工、修改员工和查询员工（全部查询和按员工编号、员工姓名、部门、职位和性别模糊查询）

公告管理：添加公告、删除公告、修改公告和查询公告（全部查询和按公告标题模糊查询）

# 开发技术：

Java EE 架构：SSM（Spring + Spring MVC + MyBatis）框架

表现层技术：JSP

前端框架：Bootstrap

数据库：MySQL

# 系统结构：

表现层：JSP 页面

MVC 控制器层：Spring MVC 技术，由一系列控制器组成。

业务逻辑层：Spring 技术，由一系列的业务逻辑对象组成。

DAO 层：MyBatis 框架，由一系列的 DAO 组件组成，这些 DAO 实现了对数据库的创建、查询、更新和删除（CRUD）等原子操作。

Domain Object 层：由一系列的 POJO（Plain Old Java Object，即普通的、传统的Java对象）组成，是一些简单的 Java Bean 类。

数据库：MySQL 数据库，进行数据持久化操作。

# 开发环境选择

IntelliJ IDEA 2017.3+或者eclipse

mysql 5.6+

Tomcat 8.0+

