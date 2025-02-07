# InVasion
<div style="text-align: center;">
    <img src="readme/repo_logo.png" />
</div>

Read this in other languages: [English](./README.md), [Русский](./README.ru.md)


## Words of gratitude:

---

On behalf of our entire team, we would like to say huge thanks to [Vitaly Selishchev](https://github.com/vvselischev), our mentor, for his invaluable contribution to the project. In addition to the main duties of the mentor, Vitaly held online meetings for us, where he helped us solve problems that we encountered as we developed, Vitaly also conducted an online code review, where he pointed out our mistakes and suggested possible alternatives for writing code that would facilitate the development process for us. And even that's not all: at almost every online meeting, Vitaly showed us various OOP patterns and methods for solving classical problems related to the creation of project architecture.


## Project Description:

---

Actions take place in the distant future. People invade an alien planet in order to capture the resources of another civilization. Two teams participate in the battle: humans and aliens.
The task of both teams is to keep the lead in points until the end of the match.


### Controls:

---

| Buttons | Action | | Buttons | Action |
| --- | --- | --- | --- | --- |
| `W` / `up` | move forward | | `E` | use aid kit / ammo crate |
| `A` / `left` | move left | | `F` | put aid kit / ammo crate |
| `S` / `down` | move backward | | `R` | reload weapon |
| `D` / `right` | move right | | `Tab` | view match statistics |
| `Esc` | open the game menu during a match | |

## Project demo:

--

### Project defense presentation (ru) - [link](https://docs.google.com/presentation/d/1lBzSjmXYhELPg0OBNJKAoncFke5LDX_C9CTU3kSo5jA/edit?usp=sharing).

### Gameplay footage:

[![InVasion - Gameplay Footage](https://img.youtube.com/vi/mrqsUgST12c/0.jpg)](https://www.youtube.com/watch?v=mrqsUgST12c)


### In-game screenshots:

<div style="text-align: center;">
    <img src="readme/screenshot_1.png" style="margin-bottom: 10px;" />
    <img src="readme/screenshot_2.png" style="margin-bottom: 10px;" />
    <img src="readme/leaderboard.png" />
</div>

### Classes abilities demonstration (Medic and Support):

Medic specialization is able to install medkit that can be used by teammates to recover hit points.

<img alt="medic abilities demonstration" src="./readme/medic-demonstration.gif" style="width:850px;"/>


Support specialization is able to install ammo crate that can be used by teammates to refill ammo supplies.

<img alt="support abilities demonstration" src="./readme/support-demonstration.gif" style="width:850px;"/>


## Project build:

---

### Client setup:

[Godot editor](https://godotengine.org/download/windows) is required. During development, we used the version `v3.4.2`, you can install it by clicking on the [link](https://downloads.tuxfamily.org/godotengine/3.4.2/).

Next, you need to open the `/client/godot/game/default_env.tres` file inside the engine, after which you can start editing the client code sources.

### Server setup: 

When building on Windows, we recommend using the [vcpkg](https://github.com/microsoft/vcpkg) package manager to install all of the following dependencies.


To build the server, you need to install [boost](https://www.boost.org/), we developed on version `v1.71.0`, it can be installed from the [link](https://www.boost.org/users/history/version_1_71_0.html).


You also need to install the [protocol buffers](https://developers.google.com/protocol-buffers/docs/downloads) compiler, we used version `v3.18.0`, it can be installed from the [link](https://github.com/protocolbuffers/protobuf/releases/tag/v3.18.0).

The last thing you need to install is [sqlite](https://www.sqlite.org/index.html).

P.S. If you have Linux and sqlite does not start, then installing additional components should solve the problem:

```sh
sudo apt update
sudo apt-get install libsqlite3-dev
sudo apt-get install sqlite3
```
