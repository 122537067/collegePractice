package com.sms.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sms.dao.IClassInfoDao;
import com.sms.iservice.IClassInfoService;
import com.sms.model.ClassInfo;

/**
 * 班级信息服务
 * @author hp
 *
 */
@Service
public class ClassInfoService implements IClassInfoService {
	
	@Autowired
	private IClassInfoDao dao;

	@Override
	public List<ClassInfo> getAllClassInfos() throws Exception {
		List<ClassInfo> data = this.dao.selectAllClassInfo();
		return data;
	}
	public void addClass(ClassInfo model) throws Exception{
		
		dao.insertClassInfo(model);
	}
	public void deleteClass(int id){
		
		try {
			dao.deleteClassInfo(id);
		} catch (Exception e) {
			
			e.printStackTrace();
		}
	}

}
