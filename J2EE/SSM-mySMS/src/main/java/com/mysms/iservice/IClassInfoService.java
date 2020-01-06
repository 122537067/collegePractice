package com.mysms.iservice;

import com.mysms.model.ClassInfo;

import java.util.List;

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

	public void insertKlass(ClassInfo klass) throws  Exception;

	public void deleteKlass(int id) throws Exception;

	public void updateKlass(ClassInfo Klass) throws Exception;

	public ClassInfo getKlassById(int id) throws Exception;

}
