package com.mysms.web;

import com.mysms.iservice.IClassInfoService;
import com.mysms.model.ClassInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@Controller
@RequestMapping("/classinfo")
public class ClassInfoController extends BaseController {
	
	@Autowired
	private IClassInfoService service;
	
	@RequestMapping(value="/list",method=RequestMethod.GET)
	public String getlist(HttpServletRequest request, HttpServletResponse response) throws IOException {
		try {
			this.validPermission(request,"ClassSearch");
		} catch (Exception e) {
			return this.exp(response,e);
		}
		return "classinfo/list";
	}
	
	@RequestMapping(value="/list",method=RequestMethod.POST)
	@ResponseBody
	public List<ClassInfo> list() throws Exception{
		return this.service.getAllClassInfos();
	}

	@RequestMapping(value = "/add",method = RequestMethod.GET)
	public String getadd(HttpServletRequest request,HttpServletResponse response) throws IOException {
		try {
			this.validPermission(request,"ClassAdd");
		} catch (Exception e) {
			return this.exp(response,e);
		}
		return "classinfo/add";
	}

	@RequestMapping(value = "/add",method = RequestMethod.POST)
	@ResponseBody
	public String add(HttpServletRequest request){
		ClassInfo klass = new ClassInfo();
		klass.setName(request.getParameter("Name"));
		klass.setNum(Integer.parseInt(request.getParameter("Num")));
		try {
			this.service.insertKlass(klass);
			return "success";
		} catch (Exception e) {
			return e.getMessage();
		}
	}

	@RequestMapping(value = "/delete",method = RequestMethod.POST)
	@ResponseBody
	public String delete(HttpServletRequest request) throws Exception {
		try {
			this.validPermission(request,"ClassDel");
			String id = request.getParameter("id");
			this.service.deleteKlass(Integer.parseInt(id));
			return "success";
		} catch (Exception e) {
			return e.getMessage();
		}
	}

	@RequestMapping(value = "/getedit",method = RequestMethod.GET)
	public String getEdit(HttpServletRequest request,HttpServletResponse response, Model model) throws Exception {
		try {
			this.validPermission(request,"ClassModify");
		} catch (Exception e) {
			return this.exp(response,e);
		}
		ClassInfo klass = this.service.getKlassById(Integer.parseInt(request.getParameter("id")));
		model.addAttribute("selectKlass",klass);
		return "/classinfo/edit";
	}

	@RequestMapping(value = "/edit",method = RequestMethod.POST)
	@ResponseBody
	public String Edit(HttpServletRequest request){
		ClassInfo Klass = new ClassInfo();
		Klass.setId(Integer.parseInt(request.getParameter("Id")));
		Klass.setName(request.getParameter("Name"));
		Klass.setNum(Integer.parseInt(request.getParameter("Num")));
		try {
			this.service.updateKlass(Klass);
			return "success";
		} catch (Exception e) {
			return e.getMessage();
		}
	}

	@RequestMapping(value = "/getdetail",method = RequestMethod.GET)
	public String getDetail(HttpServletRequest request,Model model) throws Exception {
		ClassInfo klass = this.service.getKlassById(Integer.parseInt(request.getParameter("id")));
		model.addAttribute("selectKlass",klass);
		return "/classinfo/detail";
	}
}
