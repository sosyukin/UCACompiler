#include "pch.h"
#include "Signal_Table.h"


Signal_Table::Signal_Table()
{
	
}


Signal_Table::~Signal_Table()
{
}
void Signal_Table::Createtable(TreeNode * root)
{
	Check(root);
	OutTable(root);
}
void Signal_Table::Check(TreeNode * root)
{	
	TreeNode * tmp=NULL;
	for (int i = 0; i < root->GetChildNumber(); i++)
	{
		tmp = root->GetChild(i);
		if (tmp->m_nodeType == TreeNode::TypeK)
		{
			int num = tmp->GetChildNumber();
			TreeNode * tmp2=NULL;
			for (int i = 0; i <num; i++)
			{
				tmp2 = tmp->GetChild(i);
				for (list<string>::iterator i = tmp2->m_IDList.begin(); i != tmp2->m_IDList.end(); i++)
				{
					tablenode.idname = *i;
					switch (tmp2->m_decType)
					{
					case TreeNode::IntegerK:
						tablenode.attributeir.typeattr.kind = intTy;
						break;
					case TreeNode::CharK:
						tablenode.attributeir.typeattr.kind = charTy;
						break;
					case TreeNode::ArrayK:
						tablenode.attributeir.typeattr.kind = arrayTy;  //数组类型
						if (tmp2->m_decArrayType == TreeNode::CharK)
						{
							tablenode.attributeir.typeattr.array.arraykind = charTy;
						}
						else if (tmp2->m_decArrayType == TreeNode::IntegerK)
						{
							tablenode.attributeir.typeattr.array.arraykind = intTy;
						}
						tablenode.attributeir.typeattr.array.size = ((tmp2->m_arrayLow) - (tmp2->m_arrayTop) + 1);
				
						break;
					case TreeNode::RecordK:
						TreeNode * tmpa = NULL;
						Record rtmp;
						for (int x = 0; x < tmp2->GetChildNumber(); x++)
						{
							tmpa = tmp2->GetChild(x);
							tablenode.attributeir.typeattr.kind = recordTy;
							switch (tmpa->m_decType)
							{
							case TreeNode::CharK:
								rtmp.typet.kind = charTy;
								break;
							case TreeNode::IntegerK:
								rtmp.typet.kind = intTy;
								break;
							case TreeNode::ArrayK:
								if (tmpa->m_decArrayType == TreeNode::CharK)
								{
									rtmp.typet.kind = charTy;
								}
								else if (tmpa->m_decArrayType == TreeNode::IntegerK)
								{
									rtmp.typet.kind = intTy;
								}
								break;
							}
							tablenode.attributeir.rec.recordt.insert(tablenode.attributeir.rec.recordt.end(), rtmp);
							tablenode.attributeir.rec.SetNumber();
							
						}						
						break;
					}
					table.insert(table.end(), tablenode);
				}
			}
		}
		else if (tmp->m_nodeType == TreeNode::VarK)
		{
			
			int num = tmp->GetChildNumber();
			TreeNode * tmp3 = NULL;
			for (int i = 0; i <num; i++)
			{
				tmp3 = tmp->GetChild(i);
				if (tmp3->m_nodeType == TreeNode::DecK)
				{
					for (list<string>::iterator i = tmp3->m_IDList.begin(); i != tmp3->m_IDList.end(); i++)
					{
						tablenode.idname = *i;
						tablenode.attributeir.kind = varKind;
						tablenode.attributeir.varattr.accesskind = dir;
						tablenode.attributeir.varattr.level = level;
						tablenode.attributeir.varattr.off = offset;
						switch (tmp3->m_decType)
						{
						case TreeNode::CharK:
							tablenode.attributeir.varattr.realkind = charTy;						
							offset++;
							break;
						case TreeNode::IntegerK:
							tablenode.attributeir.varattr.realkind = intTy;						
							offset++;
							break;
						case TreeNode::IdK:
							TypeKind typetmp;
							typetmp = SerchKind(tmp3->m_IdKName);
							if (typetmp == arrayTy)
							{					
								tablenode.attributeir.varattr.realkind = arrayTy;
								offset += SerchArray(tmp3->m_IdKName);
								
							}
							else if (typetmp == recordTy)
							{								
								tablenode.attributeir.varattr.realkind = recordTy;
								offset += SerchRecord(tmp3->m_IdKName);
								tablenode.attributeir.varattr.off = offset;
							}
							break;
						}
						table.insert(table.end(), tablenode);
					}					
				}
				
			}
			
		}
		else if (tmp->m_nodeType == TreeNode::ProcK)
		{
			level = 0;
			int num = tmp->GetChildNumber();
			TreeNode * tmp4 = NULL;
			tablenode.idname = *(tmp->m_IDList.begin());
			tablenode.attributeir.kind = procKind;
			level++;
			tablenode.attributeir.procattr.level = level;			
			//tablenode.attributeir.procattr.ptable.clear();
			int psize = 0;
			for (int i = 0; i <num; i++)
			{
				
				tmp4 = tmp->GetChild(i);
				if (tmp4->m_nodeType == TreeNode::DecK)
				{					
					
					ParamT tmpp;
					for (list<string>::iterator i = tmp4->m_IDList.begin(); i != tmp4->m_IDList.end(); i++)
					{
						tmpp.idname = *i;
						if (tmp4->m_decType == TreeNode::IntegerK)
						{
							tmpp.type = intTy;
							psize++;
						}
						else if (tmp4->m_decType == TreeNode::CharK)
						{
							tmpp.type = charTy;
							psize++;
						}
						if (tmp4->m_paramType == TreeNode::Var)
						{
							tmpp.accesskind = indir;
						}
						else if (tmp4->m_paramType == TreeNode::Val)
						{
							tmpp.accesskind = dir;
						}
						tablenode.attributeir.procattr.size = psize;
						tablenode.attributeir.procattr.ptable.insert(tablenode.attributeir.procattr.ptable.end(), tmpp);//插入到参数表
					}					
				}
				tablenode.nof = 7 + psize;
			}	
			
			table.insert(table.end(), tablenode);
		}
		else if (tmp->m_nodeType == TreeNode::StmLK)
		{

		}
	}

	
}

void RecordT::SetNumber()
{
	size = 0;
	for (itr = recordt.begin(); itr != recordt.end(); itr++)
	{
		if (itr->typet.array.size != 0)
		{
			size += itr->typet.array.size;
		}
		else
		{
			size++;
		}
	}

}
void Signal_Table::OutTable(TreeNode * root)
{
	if (!ErrorCheck(root))
	{
		return;
	}
	std::list<ConstNode>::iterator it = table.begin();
	std::list<ConstNode>::iterator itmp;
	cout << "-----------------Symble in level 0--------------------" << endl;
	for (it = table.begin(); it != table.end(); it++)
	{
		if (it->attributeir.kind == typeKind)
		{
			std::string stmp;
			switch (it->attributeir.typeattr.kind)
			{
			case intTy:
				stmp = "intTy";
				break;
			case charTy:
				stmp = "charTy";
				break;
			case arrayTy:
				stmp = "arrayTy";
				break;
			case recordTy:
				stmp = "recordTy";
				break;
			}
			cout << std::setw(20) << it->idname << ":" << std::setw(10) << stmp << std::setw(10) << "typeKind" << endl;
		}
		else if (it->attributeir.kind == varKind)
		{
			std::string stmp;
			switch (it->attributeir.varattr.realkind)
			{
			case intTy:
				stmp = "intTy";
				break;
			case charTy:
				stmp = "charTy";
				break;
			case arrayTy:
				stmp = "arrayTy";
				break;
			case recordTy:
				stmp = "recordTy";
				break;
			}
			cout << std::setw(20) << it->idname << ":" << std::setw(10) << stmp << std::setw(10) << "varKind" << std::setw(10) << "Level=0" << std::setw(10) << "Offset=" << it->attributeir.varattr.off << std::setw(10) << "dir" << endl;
		}
		else if (it->attributeir.kind == procKind)
		{
			itmp = it;
			cout << std::setw(20) << it->idname << ":" << std::setw(10) << "funcKind" << std::setw(10) << "NOF=" << it->nof << std::setw(10) << "Level=" << it->attributeir.procattr.level << endl;
		}
		
	}
	ShowParam(itmp);
}
int Signal_Table::SerchArray(std::string idname)
{
	std::list<ConstNode>::iterator it;
	for (it = table.begin(); it != table.end(); it++)
	{
		if (it->idname==idname)
		{
			
			return it->attributeir.typeattr.array.size;
			
		}
	}
}
TypeKind Signal_Table::SerchKind(std::string idname)
{
	std::list<ConstNode>::iterator it;
	for (it = table.begin(); it != table.end(); it++)
	{
		if (it->idname == idname)
		{
			return it->attributeir.typeattr.kind;
		}
	}
	
}
int Signal_Table::SerchRecord(std::string idname)
{
	std::list<ConstNode>::iterator it;
	for (it = table.begin(); it != table.end(); it++)
	{
		if (it->idname == idname)
		{
			return it->attributeir.rec.size;
		}
	}
	return 0;
}
void Signal_Table::ShowParam(std::list<ConstNode>::iterator it)
{
	cout << "-----------------Symble in level " << it->attributeir.procattr.level << "--------------------" << endl;
	std::list<ParamT>::iterator pit = it->attributeir.procattr.ptable.begin();
	int i = 7;
	for (pit; pit != it->attributeir.procattr.ptable.end();pit++)
	{
		std::string stmp1,stmp2,stmp3;
		if (pit->type==0)
		{
			stmp1 = "intTy";
		}
		else if (pit->type == 1)
		{
			stmp1 = "charTy";
		}
		if (pit->accesskind == 0)
		{
			stmp2 = "dir";
		}
		else if (pit->accesskind == 1)
		{
			stmp2 = "indir";
		}
		switch (pit->type)
		{
		case intTy:
			stmp3 = "intTy";
			break;
		case charTy:
			stmp3 = "charTy";
			break;
		case arrayTy:
			stmp3 = "arrayTy";
			break;
		case recordTy:
			stmp3 = "recordTy";
			break;
		}
		
		cout << std::setw(20) << pit->idname << ":" << std::setw(10) << stmp3 << std::setw(10) << "varKind" << std::setw(10) << "Level=" << it->attributeir.procattr.level << std::setw(10) << "Offset=" << i++ << std::setw(10) << stmp2 << endl;
	}
}
bool Signal_Table::ErrorCheck(TreeNode * root)
{
	if (!ErrorUndefine(root))
	{
		return false;
	}
	std::list<ConstNode>::iterator it = table.begin();
	std::list<ConstNode>::iterator tmp;
	for ( it; it != table.end(); it++)
	{
		tmp = it;
		tmp++;
		for (tmp; tmp != table.end(); tmp++)
		{
			if (it->idname==tmp->idname)
			{
				cout << tmp->idname<<"重定义" << endl;
				return false;
			}
		}
	}
	cout << "无语义错误" << endl;
	return true;
}
bool Signal_Table::ErrorUndefine(TreeNode * root)
{
	TreeNode * tmp = NULL;
	TreeNode * tmp2 = NULL;
	TreeNode * tmp3 = NULL;
	TreeNode * tmp4 = NULL;
	TreeNode * tmp5 = NULL;
	TreeNode * tmp6 = NULL;
	TreeNode * tmp7 = NULL;
	TreeNode * tmp8 = NULL;
	TreeNode * tmp9 = NULL;
	std::string strtmp;
	for (int i = 0; i < root->GetChildNumber(); i++)
	{
		tmp = root->GetChild(i);
		if (tmp->m_nodeType == TreeNode::StmLK)
		{
			for (int i = 0; i < tmp->GetChildNumber(); i++)
			{
				tmp2 = tmp->GetChild(i);
				if (tmp2->m_nodeType == TreeNode::StmtK)
				{
					if (tmp2->m_stmtType == TreeNode::AssignK)
					{
						for (int i = 0; i < tmp2->GetChildNumber(); i++)
						{
							tmp3 = tmp2->GetChild(i);
							if (tmp3->m_expType==TreeNode::VariK)
							{								
								strtmp = *(tmp3->m_IDList.begin());
								if (!CheckId(strtmp))
								{
									cout << "未定义标识符" << strtmp << endl;
									return false;
								}
							}
														
						}
					}
					else if (tmp2->m_stmtType == TreeNode::IfK)
					{
						for (int i = 0; i < tmp2->GetChildNumber(); i++)
						{
							tmp4 = tmp2->GetChild(i);
							if (tmp4->m_stmtType == TreeNode::AssignK)
							{
								for (int i = 0; i < tmp4->GetChildNumber(); i++)
								{
									tmp5 = tmp4->GetChild(i);
									if (tmp5->m_expType == TreeNode::VariK)
									{
										strtmp = *(tmp5->m_IDList.begin());
										if (!CheckId(strtmp))
										{
											cout << "未定义标识符" << strtmp << endl;
											return false;
										}
									}

								}
							}
							else if (tmp4->m_stmtType == TreeNode::OpK)
							{
								for (int i = 0; i < tmp4->GetChildNumber(); i++)
								{
									tmp9 = tmp4->GetChild(i);
									if (tmp9->m_expType == TreeNode::VariK)
									{
										strtmp = *(tmp9->m_IDList.begin());
										if (!CheckId(strtmp))
										{
											cout << "未定义标识符" << strtmp << endl;
											return false;
										}
									}

								}
							}
						}
					}
					else if (tmp2->m_stmtType == TreeNode::WhileK)
					{
						for (int i = 0; i < tmp2->GetChildNumber(); i++)
						{
							tmp6 = tmp2->GetChild(i);
							if (tmp6->m_stmtType == TreeNode::AssignK)
							{
								for (int i = 0; i < tmp6->GetChildNumber(); i++)
								{
									tmp7 = tmp6->GetChild(i);
									if (tmp7->m_expType == TreeNode::VariK)
									{
										strtmp = *(tmp7->m_IDList.begin());
										if (!CheckId(strtmp))
										{
											cout << "未定义标识符" << strtmp << endl;
											return false;
										}
									}

								}
							}
						}
					}
					else if (tmp2->m_stmtType == TreeNode::CallK)
					{
						for (int i = 0; i < tmp2->GetChildNumber(); i++)
						{
							tmp8 = tmp2->GetChild(i);
							if (tmp8->m_expType == TreeNode::VariK)
							{
								strtmp = *(tmp8->m_IDList.begin());
								if (!CheckId(strtmp))
								{
									cout << "未定义标识符" << strtmp << endl;
									return false;
								}
							}
						}
					}					
				}			
			}
		}
	}
	return true;
}
bool Signal_Table::CheckId(std::string idname)
{
	std::list<ConstNode>::iterator it = table.begin();
	for (it; it != table.end(); it++)
	{
		if (idname==it->idname)
		{
			return true;
		}
	}
	return false;
}