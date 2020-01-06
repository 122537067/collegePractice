package com.sms.iservice;

import java.util.List;

import com.sms.model.ClassInfo;

/**
 * 班级信息服务接口
 * @author hp
 *
 */
public interface IClassInfoService {
	
	/**
	 * 获取所有班级信息
	 * @return
	 * @throws Exception 
	 */
	public List<ClassInfo> getAllClassInfos() throws Exception;
	public void addClass(ClassInfo model) throws Exception;
	public void deleteClass(int id);
}
