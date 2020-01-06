package service;

import java.util.List;

import dao.UserInfoDao;
import model.UserInfo;

public class UserFunctionService {
	public UserFunctionService() {
		super();
	}
	
	public List<UserInfo> Setlist() throws Exception{
		List<UserInfo> getlist= new UserInfoDao().query(null);
		return getlist;
	}
	
	public List<UserInfo> Findlist(String name) throws Exception {
		List<UserInfo> getlist= new UserInfoDao().query(name);
		return getlist;
	}
	
	public void Useradd(String name,String pass) {
		UserInfoDao dao = new UserInfoDao();
		UserInfo Info = new UserInfo();
		Info.setUsername(name);
		Info.setPassword(pass);
		try {
			dao.add(Info);
		} catch (Exception e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
	
	public void Userdelete(String id) {
		UserInfoDao dao = new UserInfoDao();
		try {
			dao.delete(Long.parseLong(id));
		} catch (Exception e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
	
	public void Userdomodify(String id,String name,String pass) {
		UserInfoDao dao = new UserInfoDao();
		UserInfo Info = new UserInfo();
		Info.setId(Long.parseLong(id));
		Info.setUsername(name);
		Info.setPassword(pass);
		try {
			dao.update(Info);
		} catch (Exception e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
}
