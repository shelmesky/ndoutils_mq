
#### Nagios的Ndoutils增加向RabbitMQ Server发送消息并存储到MongoDB的功能。

过程: 将消息转换为JSON格式后，通过RabbitMQ的C客户端发送到服务器, 并存储到MongoDB。

#### 安装方法：

按照正常方法安装ndoutils和RabbitMQ服务器，并将ndomod加载到Nagios中，设置配置文件为：/etc/nagios3/ndomod.cfg。

具体为在nagios.cfg中增加以下配置：

```text
broker_module=path_to_ndomod-3x.o config_file=/etc/nagios3/ndomod.cfg 
```

#### 配置RabbitMQ:

在ndomod.cfg配置文件中增加以下内容:

```bash
# 是否打开NEB向RabbitMQ发送消息的功能
rabbitmq_enabled=1
    
# RabbitMQ主机
rabbitmq_hostname=127.0.0.1
# RabbitMQ端口
rabbitmq_port=5672
# RabbitMQ用户名
rabbitmq_username=guest
# RabbitMQ密码
rabbitmq_password=guest

# RabbitMQ的virtualhost，默认为/
rabbitmq_virtualhost=/
# 发送消息使用的exchange名称
rabbitmq_exchange=nagios
# 发送消息使用的routing key
rabbitmq_routingkey=nagios
```

增加以上内容完毕保存，运行目录下的recv.py::

```bash
python recv.py
```

并重启nagios3服务，观察Nagios3的WEB控制台的Event Log有以下输出:

```
[2013-07-25 16:33:39] NEB message will send to RabbitMQ: [127.0.0.1:5672] [virtualhost:/ exchange:nagios routingkey:nagios]
[2013-07-25 16:33:39] RabbitMQ Init Success.
[2013-07-25 16:33:39] RabbitMQ Library Init...
```

表示功能正常工作，并可以看到python的客户端已经从RabbitMQ收到消息。 

#### 配置MongoDB:

在ndomod.cfg中增加以下内容::

```bash
# Configuration for MongoDB
mongodb_enabled=1
    
mongodb_hostname=127.0.0.1
mongodb_port=27017

# leave username and password empty for NO Auth!
mongodb_username=
mongodb_password=

mongodb_database=wisemonitor
```

重启Nagios3服务，会在Nagios3的WEB控制台的Event Log有以下输出:

```
[2013-09-02 11:51:35] MongoDB has connected to 127.0.0.1:27017
```

同时会在MongoDB中生成以下Collection:

```text
nagios_instance 当有多个Nagios实例时，存储每个实例的信息
nagios_objects  每个实例的对象，例如主机和服务定义
nagios_hosts    主机定义
nagios_host_status 主机的最新状态
nagios_services 服务定义
nagios_service_status 服务的最新状态
```

