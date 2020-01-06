package com.sms.web;

import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.sms.iservice.IClassInfoService;
import com.sms.model.ClassInfo;
import com.sms.model.ReturnData;

@Controller
@RequestMapping("/classinfo")
public class ClassInfoController extends BaseController {
	
	@Autowired
	private IClassInfoService service;
	@RequestMapping(value="/delete",method=RequestMethod.POST) 
    public String deleteClass(HttpServletRequest request,HttpServletResponse response) {
		
		int id=Integer.parseInt(request.getParameter("id"));
		ReturnData rd = new ReturnData();
        	service.deleteClass(id);
        	rd.setSuccess(true);
			rd.setMessage("删除用户成功");
			
        
		return "classinfo/list";
     
    }
	@RequestMapping(value="/list",method=RequestMethod.GET)
	public String list(HttpServletRequest request){
		return "classinfo/list";
	}
	
	@RequestMapping(value="/list",method=RequestMethod.POST)
	@ResponseBody
	public List<ClassInfo> list() throws Exception{
		List<ClassInfo> data = this.service.getAllClassInfos();
		return data;
	}
	
	
	@RequestMapping(value="/add",method=RequestMethod.GET)
	public String add(HttpServletRequest request){
		return "classinfo/add";
	}
	
	
	@RequestMapping("/addClass") 
    public String addClass(ClassInfo model) throws Exception{
        if(model != null){
        	service.addClass(model);
        }
		return "classinfo/list";
     
    }
	

}
