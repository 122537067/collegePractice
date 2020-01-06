package com.mysms.model;

import java.util.List;

public class RoleInfo {

    private int id;
    private String name;
    private List<FunctionInfo> functions;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
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

    public void setFunctions(List<FunctionInfo> function) {
        this.functions = function;
    }
}
