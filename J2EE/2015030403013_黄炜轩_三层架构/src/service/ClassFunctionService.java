package service;

import java.util.List;

import dao.ClassInfoDao;
import dao.UserInfoDao;
import model.ClassInfo;
import model.UserInfo;

public class ClassFunctionService {
	public ClassFunctionService() {
	}
	
	public List<ClassInfo> Setlist() throws Exception{
		List<ClassInfo> getlist= new ClassInfoDao().query(null);
		return getlist;
	}
	
	public List<ClassInfo> Findlist(String name) throws Exception{
		List<ClassInfo> getlist= new ClassInfoDao().query(name);
		return getlist;
	}
	
	public void Classadd(String name) {
		ClassInfoDao dao = new ClassInfoDao();
		ClassInfo Info = new ClassInfo();
		Info.setName(name);
		try {
			dao.add(Info);
		} catch (Exception e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
	
	public void Classdelete(String id) {
		ClassInfoDao dao = new ClassInfoDao();
		try {
			dao.delete(Long.parseLong(id));
		} catch (Exception e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
	
	public void Classdomodify(String id,String name) {
		ClassInfoDao dao = new ClassInfoDao();
		ClassInfo Info = new ClassInfo();
		Info.setId(Long.parseLong(id));
		Info.setName(name);
		try {
			dao.update(Info);
		} catch (Exception e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
}
