package com.zhengjiaxin.service;
import java.util.ArrayList;
import java.util.List;

import org.json.JSONObject;

import com.zhengjiaxin.dao.ClassInfoDao;
import com.zhengjiaxin.model.ClassInfo;
public class ClassInfoService {
	public List<ClassInfo> Query(String name) throws Exception{
		
		List<ClassInfo> list = new ArrayList<ClassInfo>();
		list = new ClassInfoDao().query(name);
		
		return list;
	}
	
	public void delete(long id) throws Exception{
		
		new ClassInfoDao().delete(id);
	}
	
	public void update(ClassInfo model) throws Exception{
		
		new ClassInfoDao().update(model);
	}
	
	public void add(ClassInfo model) throws Exception{
		
		new ClassInfoDao().add(model);
	}
	
	public String getClassInfoJsonData() throws Exception{
		List<ClassInfo> classes = new ClassInfoDao().query(null);
		String jsonData = JSONObject.valueToString(classes);
		return jsonData;
	}
}
