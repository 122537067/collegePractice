package com.sms.test;

import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import com.sms.dao.ClassInfoDao;
import com.sms.dao.DbHelper;
import com.sms.model.ClassInfo;

public class test {
	
	public static void main(String args[]) throws Exception
	{
		Show_Class();
		Update_Class(7);
		Show_Class();
	}
	
	//列出课室信息
	private static void Show_Class() throws Exception 
	{
		ClassInfoDao dao = new ClassInfoDao();	
		System.out.println("==================================");
		System.out.println("ID      No.             Name");
		List<ClassInfo> list = dao.printTable(null, null);  //读取表格信息存进list
		for(ClassInfo model:list)
		{
			System.out.println(model);  //输出list信息
		}
		System.out.println("==================================");
	}
	
	//增加课室信息
	private static void Add_Class(String no,String name) throws Exception 
	{
		ClassInfoDao dao = new ClassInfoDao();
		ClassInfo model = new ClassInfo();
		model.setNo(no);
		model.setName(name);
		dao.add(model);
		System.out.println("add-->No:"+no+",Name:"+name+"   .....success");
	}
	
	//通过ID删除课室信息
	private static void Delete_Class(int id) throws Exception 
	{
		ClassInfoDao dao = new ClassInfoDao();
		ClassInfo model = dao.Get_Class(id);
		dao.delete(model);
	}
	
	//通过ID更新课室信息
	private static void Update_Class(int id) throws Exception 
	{
		ClassInfoDao dao = new ClassInfoDao();
		ClassInfo model = dao.Get_Class(id);
		model.setNo("8948");
		model.setName("ffff5");
		dao.update(model);
		
	}
}





















