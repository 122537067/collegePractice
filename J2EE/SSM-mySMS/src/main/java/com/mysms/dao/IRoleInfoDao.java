package com.mysms.dao;

import com.mysms.model.FunctionInfo;
import com.mysms.model.RoleInfo;

import java.util.List;

public interface IRoleInfoDao {

    public List<FunctionInfo> getFunctions(int roleId) throws Exception;

}
