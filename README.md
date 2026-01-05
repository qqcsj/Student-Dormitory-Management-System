# 基于Visual Studio 中的MFC图形化界面实现的学生宿舍管理系统

## 项目简介
这是一个使用 **Visual Studio** 和 **MFC（Microsoft Foundation Classes）** 开发的图形化学生宿舍管理系统。系统实现了宿舍信息的增删改查功能，并通过与文本文件交互实现数据持久化。项目包含两个主要模块：
1. **学生宿舍信息管理系统**
2. **宿舍维修系统**

## 功能展示

### 登录界面
- 用户名和密码验证。
- 初始用户名和密码：
  - 用户名：`admin` / `张三`
  - 密码：`admin123` / `zhangsan123`
- 输入错误或未输入时，通过 `MessageBox` 显示提示信息。

### 学生信息管理功能
- **打开文件**：与 `.txt` 文本文件交互，加载数据。
- **添加学生**：输入完整信息后添加新学生，未打开文件或信息不完整时提示错误。
- **删除学生**：选择某行数据后删除。
- **修改学生信息**：选择某行数据后修改信息。
- **查找学生**：根据学号查找学生信息。
- **保存数据**：将修改后的数据保存回文本文件。
- **退出系统**：退出当前系统并进入宿舍维修模块。

### 宿舍维修系统
- **打开文件**：加载维修记录。
- **添加维修记录**：支持手动填写维修状态（如“待处理”、“处理中”、“已完成”）。
- **修改维修记录**：选择某行数据后修改内容。
- **删除维修记录**：选择某行数据后删除。
- **保存数据**：将数据同步到文本文件。
- **返回主界面**：退出整个系统。

## 系统截图
### 登录界面
<img width="865" height="624" alt="image" src="https://github.com/user-attachments/assets/cb399f0f-62df-4563-aaa9-d73976a946cd" />


### 登录提示信息
<img width="733" height="540" alt="image" src="https://github.com/user-attachments/assets/619fbb8c-0011-4dcb-961d-0a4e1d702165" />


### 用户名或密码错误提示
<img width="865" height="648" alt="image" src="https://github.com/user-attachments/assets/1f80534a-7b65-448c-b859-54596a24ec04" />


### 登录成功界面
<img width="786" height="573" alt="image" src="https://github.com/user-attachments/assets/a5b6aa05-a09a-4d38-b275-33b52c2d3206" />


### 添加学生信息界面
<img width="729" height="373" alt="image" src="https://github.com/user-attachments/assets/10a373df-2565-460f-adba-019b04850b48" />


### 删除学生信息提示
<img width="765" height="392" alt="image" src="https://github.com/user-attachments/assets/28ec7570-6d25-4ac8-a346-74d161036560" />
<img width="741" height="347" alt="image" src="https://github.com/user-attachments/assets/203cf78f-8520-4715-a991-c09cc493afc7" />



### 修改学生信息界面
<img width="839" height="321" alt="image" src="https://github.com/user-attachments/assets/8aa80e07-122a-4f90-a9bc-3d713632b7f1" />


### 查找学生信息界面
<img width="865" height="472" alt="image" src="https://github.com/user-attachments/assets/0250924c-e284-4562-bbc1-40a1a0c38458" />


### 宿舍维修系统界面
<img width="864" height="719" alt="image" src="https://github.com/user-attachments/assets/4631c302-3c19-4e5a-9b11-10e1804e3ac2" />


### 宿舍维修系统——打开维修文件
<img width="707" height="508" alt="image" src="https://github.com/user-attachments/assets/2f55cb6e-ad9b-4379-b312-53d6e8a9ddb1" />



### 宿舍维修系统——添加维修记录
<img width="796" height="650" alt="image" src="https://github.com/user-attachments/assets/f79c7bf2-9c82-4ac6-8de1-61dee5789d51" />
<img width="584" height="360" alt="image" src="https://github.com/user-attachments/assets/5d10a1b9-ef3f-46f6-8b42-3b1518996ee9" />


### 宿舍维修系统——修改维修记录
<img width="704" height="733" alt="image" src="https://github.com/user-attachments/assets/d6709905-68f4-4030-b25b-020de7bd2636" />



### 宿舍维修系统——删除维修记录
<img width="670" height="544" alt="image" src="https://github.com/user-attachments/assets/49385ac4-6197-4f6a-b584-aa6f062302fe" />



### 宿舍维修系统——查看维修记录
<img width="798" height="693" alt="image" src="https://github.com/user-attachments/assets/7b601467-3f9b-46af-ab8d-d4045a7132a2" />



### 宿舍维修系统——保存维修记录
<img width="864" height="710" alt="image" src="https://github.com/user-attachments/assets/e187b6af-7a4b-4fbc-b55f-5e2bdd42483d" />



## 使用说明
1. 启动程序后，进入登录界面。
2. 输入用户名和密码，点击“登录”进入系统主界面。
3. 在主界面中，可以通过菜单或按钮操作进行以下功能：
   - 打开文件
   - 添加、删除、修改学生信息
   - 查找学生
   - 保存数据
   - 退出系统进入宿舍维修模块
4. 在宿舍维修模块中，可以进行维修记录的添加、修改、删除和保存操作。

## 技术说明
- 使用 **MFC** 实现图形化界面。
- 使用 **文本文件** 进行数据持久化。
- 使用 `MessageBox` 实现模态提示。
- 支持多模块切换（学生管理 <-> 维修管理）。

## 开发环境
- **开发工具**：Visual Studio
- **编程语言**：C++
- **框架**：MFC (Microsoft Foundation Classes)

## 项目结构
项目由多个 `.cpp` 和 `.h` 文件组成，包含：
- 登录界面逻辑
- 主界面逻辑
- 学生信息管理模块
- 宿舍维修管理模块
- 数据文件交互模块

## 项目截图汇总
更多界面截图请参考原始 README 中提供的图片链接。

## 开发心得
本项目经历了从面向过程到面向对象的思维转变 
初期: 使用静态数组和 switch 循环构建了命令行版本，实现了基础逻辑。
进阶: 引入类 (Class) 封装数据与操作，利用继承与多态处理不同角色的权限。
最终: 结合 MFC 框架，实现了逻辑层与视图层的分离，通过消息响应机制（Message Mapping）处理用户交互，极大提升了用户体验。
版权信息: 本项目代码仅用于学术交流与学习，未经允许请勿用于商业用途。
