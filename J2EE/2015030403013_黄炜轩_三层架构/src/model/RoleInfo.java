package model;

import java.util.List;

public class RoleInfo {
	
	private long id;
	private String code;
	private String name;
	private List<FunctionInfo> functions;
	
	public long getId() {
		return id;
	}
	public void setId(long id) {
		this.id = id;
	}
	public String getCode() {
		return code;
	}
	public void setCode(String code) {
		this.code = code;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}

	public List<FunctionInfo> getFunctions() {
		return functions;
	}
	public void setFunctions(List<FunctionInfo> functions) {
		this.functions = functions;
	}
	
}

