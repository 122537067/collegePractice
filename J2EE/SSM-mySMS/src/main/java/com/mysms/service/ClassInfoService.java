package com.mysms.service;

import com.mysms.dao.IClassInfoDao;
import com.mysms.iservice.IClassInfoService;
import com.mysms.model.ClassInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

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
		return this.dao.selectAllClassInfo();
	}

	@Override
	public void insertKlass(ClassInfo klass) throws Exception {
		int i = this.dao.insertClassInfo(klass);
		if(i==0) throw new Exception("增加失败");
	}

	@Override
	public void deleteKlass(int id) throws Exception {
		int i = this.dao.deleteClassInfo(id);
		if(i==0) throw new  Exception("删除失败");
	}

	@Override
	public void updateKlass(ClassInfo Klass) throws Exception {
		int i = this.dao.updateClassInfo(Klass);
		if(i==0) throw new Exception("修改失败");
	}

	@Override
	public ClassInfo getKlassById(int id) throws Exception {
		return this.dao.selectClassInfoById(id);
	}

}
