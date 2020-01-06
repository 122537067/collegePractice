package dao;

import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;


import model.FunctionInfo;

import dao.BaseDao;
import dao.DbHelper;

public class RoleInfoDao extends BaseDao {
	
	public RoleInfoDao() {
		super();
	}


	public List<FunctionInfo> getFunctions(long roleId) throws Exception{
		
		List<FunctionInfo> list = new ArrayList<FunctionInfo>();
		
		String sql = "select * from FunctionInfo where Id in (select FunctionInfoId from RoleFunctionPermission where RoleInfoId=?)";
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("RoleInfoId",roleId);
		
		DbHelper db = this.createDbHelper();
		
		db.createConnection();
		
		ResultSet rs = db.query(sql, param);
		

		while(rs.next()){
			FunctionInfo model = new FunctionInfo();
			model.setId(rs.getLong(1));
			model.setCode(rs.getString(2));
			model.setName(rs.getString(3));
			
			list.add(model);
		}
		
		db.closeConnection();
		
		return list;
	}

}
