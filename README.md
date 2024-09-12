### Interview Question
算法验证 GoogleTest应用验证
#### build
  1. 构建目录设置须: ./build
  2. 支持多平台构建，默认mingw8.1构建通过
#### 项目结构
  ···
  ├─3rdparty
  │  ├─GTest-1.8.x
  ├─App
  │  ├─CommonInclude
  │  ├─ProConfig
  │  └─UiFrame
  ├─build
  └─Modules
      ├─InterviewQuestion
      └─TestModule
  ···
#### 提示
如果需要项目业务和test分离，只需将App设置为Test，新增项目业务入口
