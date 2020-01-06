package UserInfo;

import java.util.List;

import RoleInfo.FunctionInfo;
import RoleInfo.RoleInfo;

public class UserInfo {
	
	private long id;
	
	private String username;
	
	private String password;
	
	private List<RoleInfo> roles;

	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}
	
	public List<RoleInfo> getRoles() {
		return roles;
	}

	public void setRoles(List<RoleInfo> roles) {
		this.roles = roles;
	}
	
	public boolean hasThePermission(String functionCode){
		for(RoleInfo role:roles){
			for(FunctionInfo f:role.getFunctions()){
				if(f.getCode().equals(functionCode)) return true;
			}
		}
		
		return false;
	}
}
