package com.demo;

import java.util.Date;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

public class FirstLevelTitleDaoTest {
	
	public static void main(String[] args) throws Exception{
		
		FirstLevelTitleDao dao = new FirstLevelTitleDao();
		
		System.out.println("==================");
		List<FirstLevelTitle> list = dao.query(null, null);
		for(FirstLevelTitle model:list){
			System.out.println(model);
		}
		
		// LinkedHashMap保持顺序和添加一致
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("TitleName", "%dao%");
		
		list = dao.query(" where TitleName like ?", param);
		
		System.out.println("==================");
		for(FirstLevelTitle model:list){
			System.out.println(model);
		}
		
		System.out.println("ok");
	}
	
	private static void testAdd() throws Exception{
		FirstLevelTitleDao dao = new FirstLevelTitleDao();
		
		FirstLevelTitle model = new FirstLevelTitle();
		model.setId(5);
		model.setTitleName("dao测试");
		model.setCreator("管理员");
		model.setCreateTime(new Date());
		
		dao.add(model);
	}
	
	private static void testUpdate() throws Exception{
		FirstLevelTitleDao dao = new FirstLevelTitleDao();
		
		FirstLevelTitle model = dao.get(2);
		System.out.println(model);
		
		model.setTitleName("dao修改");
		dao.update(model);
	}

}
