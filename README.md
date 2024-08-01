<!-- <p align="center">
  <a href="" rel="noopener">
 <img width=200px height=200px src="https://i.imgur.com/6wj0hh6.jpg" alt="Project logo"></a>
</p> -->

<h1 align="center">gz_rtf_publisher</h1>

<div align="center">

  [![GitHub issues](https://img.shields.io/github/issues/leggedrobotics-usp/gz_rtf_publisher)](https://github.com/leggedrobotics-usp/gz_rtf_publisher/issues)
  ![GitHub pull requests](https://img.shields.io/github/issues-pr/leggedrobotics-usp/gz_rtf_publisher)
  [![GitHub forks](https://img.shields.io/github/forks/leggedrobotics-usp/gz_rtf_publisher)](https://github.com/leggedrobotics-usp/gz_rtf_publisher/network)
  [![GitHub stars](https://img.shields.io/github/stars/leggedrobotics-usp/gz_rtf_publisher)](https://github.com/leggedrobotics-usp/gz_rtf_publisher/stargazers)
  [![GitHub license](https://img.shields.io/github/license/leggedrobotics-usp/gz_rtf_publisher)](https://github.com/leggedrobotics-usp/gz_rtf_publisher/blob/main/LICENSE)

</div>

---

<p align="center"> A simple ROS node for publishing the Gazebo Real Time Factor (RTF) to a ROS topic.
    <br>
</p>

## 📝 Table of Contents
- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Feature requests](#feature_requests)
- [Contributing](#contributing)
- [Author](#author)

## 🧐 About <a name = "about"></a>
**gz_rtf_publisher** is a simple ROS node that subscribes to the ```/stats``` Gazebo (Ignition) topic and publishes the Real Time Factor (RTF) to a user-specified ROS topic.

Note that using this package is required only when using modern Gazebo (Ignition). In Gazebo Classic, the Real Time Factor is available inside the ```/gazebo/performance_metrics``` ROS topic.

Making this data available outside the Gazebo GUI makes using the headless mode more effective. Instead of keeping the GUI open just to keep track of the RTF, exposing it using a topic enables the developer to monitor this data using tools such as ```ros2 topic echo``` or the Foxglove [Table panel](https://docs.foxglove.dev/docs/visualization/panels/table)

## 🏁 Getting Started <a name = "getting_started"></a>
This repo is a standard ROS2 package (ament_cmake).

### 🛠 Prerequisites

- A ROS2 workspace (colcon)
    - See [this tutorial](https://docs.ros.org/en/rolling/Tutorials/Beginner-Client-Libraries/Creating-A-Workspace/Creating-A-Workspace.html) to learn how to create your own workspace.

- libgz-transport
    - ```bash
      sudo apt install libgz-transport11-dev
      ```
    - This version (11) corresponds to the default version of modern Gazebo that ships with ROS2 Iron. Minor adjustments may be required depending on your Gazebo version.

### 💻 Installing

As mentioned above, this repo is a standard ROS2 package. Thus, you simply have to clone it inside your workspace's **src** directory.

```bash
cd <path_to_your_ros2_ws>/src
git clone https://github.com/leggedrobotics-usp/gz_rtf_publisher.git
```

Then, use **colcon** to build.

```bash
cd <path_to_your_ros2_ws>
colcon build --symlink-install
```

## 🎈 Usage <a name="usage"></a>

Each instance of **gz_rtf_publisher** binds to the ```/stats``` Gazebo topic and exposes the Real Time Factor using a Float64 ROS topic. Default topic name is ```/gazebo/real_time_factor``` and user can specify through command-line as follows:

```bash
ros2 run gz_rtf_publisher gz_rtf_publisher --ros-args -p topic_name:=<your_topic_name>
```

After starting the node, it is possible to use ``ros2 topic list`` to view the Real Time Factor.

## 🔋 Feature requests <a name="feature_requests"></a>

Want another feature? Open an *Enhancement* issue describing it.

## 🤝 Contributing <a name="contributing"></a>

- Fork the repo
  - <https://github.com/leggedrobotics-usp/gz_rtf_publisher/fork>
- Check out a new branch based and name it to what you intend to do:
  - ````bash
    git checkout -b BRANCH_NAME
    ````
- Commit your changes
  - Please provide a git message that explains what you've done;
  - Commit to the forked repository.
    ````bash
    git commit -m "A short and relevant message"
    ````
- Push to the branch
  - ````bash
    git push origin BRANCH_NAME
    ````
- Make a pull request!

## ✍️ Author <a name = "author"></a>

<a href="https://github.com/Vtn21">
 <img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/13922299?s=460&u=2e2554bb02cc92028e5cba651b04459afd3c84fd&v=4" width="100px;" alt=""/>
 <br />
 <sub><b>Victor T. N. 🤖</b></sub></a>

Made with ❤️ by [@Vtn21](https://github.com/Vtn21)

<!-- [![Gmail Badge](https://img.shields.io/badge/-victor.noppeney@usp.br-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:victor.noppeney@usp.br)](mailto:victor.noppeney@usp.br) -->

<!-- -  - Idea & Initial work -->

<!-- See also the list of [contributors](https://github.com/kylelobo/The-Documentation-Compendium/contributors) who participated in this project. -->
