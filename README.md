<!-- ================= LOGO SECTION ================= -->
<br><br>
<p align="center">
    <img src="asset/png/logo.png" width="200">
</p>


<!-- ================= DESCRIPTION SECTION ================= -->
<br><br>

<h1 align="center" style="color:#40e0d0;">
        TURQUOISE SCRIPT LANGUAGE
    </h1>
    <h3 align="center" style="color:#29abe2;">
        Game Development Language
</h3>
<p align="center">
  <img src="https://img.shields.io/badge/license-MIT-29abe2">
  <img src="https://img.shields.io/badge/status-experimental-29abe2">
  <img src="https://img.shields.io/badge/language-C++-29abe2">
</p>
<br><br>


<!-- ================= CONTENT SECTION ================= -->
<h1 id="content" align="center" style="color:#40e0d0;">CONTENTS</h1>
<ul>
    <li><a href="#license" style="color:#29abe2;">License</a></li>
    <li><a href="#installation" style="color:#29abe2;">Installation</a>
    <ul> 
        <li><a href="#setuppackage" style="color:#29abe2;">With the Package Manager</a></li>
    </ul>
    <ul> 
        <li><a href="#setupsource" style="color:#29abe2;">Compilation from the Source</a></li>
    </ul>
    </li>
    <li><a href="#syntax" style="color:#29abe2;">Syntax</a>
      <ul> 
        <li><a href="#syntaxexample" style="color:#29abe2;">Example</a></li>
      </ul>
      <ul> 
        <li><a href="#syntaxclass" style="color:#29abe2;">Class</a></li>
      </ul>
      <ul> 
        <li><a href="#syntaxprivateclass" style="color:#29abe2;">Private Class</a></li>
      </ul>
      <ul> 
        <li><a href="#syntaxgameo" style="color:#29abe2;">GameObject</a></li>
      </ul>
      <ul> 
        <li><a href="#syntexprivategameo" style="color:#29abe2;">Private GameObject</a></li>
      </ul>
      <ul> 
        <li><a href="#syntaxprefab" style="color:#29abe2;">Prefab</a></li>
      </ul>
      <ul> 
        <li><a href="#syntaxprivateprefab" style="color:#29abe2;">Private Prefab</a></li>
      </ul>
      <ul> 
        <li><a href="#syntaxcomponent" style="color:#29abe2;">Component</a></li>
      </ul>
      <ul> 
        <li><a href="#syntaxprivatecomponent" style="color:#29abe2;">Private Component</a></li>
      </ul>
      <ul> 
        <li><a href="#syntexfunction" style="color:#29abe2;">Function</a></li>
      </ul>
      <ul> 
        <li><a href="#syntexprivatefunction" style="color:#29abe2;">Private Function</a></li>
      </ul>
      <ul> 
        <li><a href="#syntaxvariables" style="color:#29abe2;">Variables</a></li>
      </ul>
      <ul> 
        <li><a href="#syntaxgamevariables" style="color:#29abe2;">GameObject Variables</a></li>
      </ul>
    </li>
    <li><a href="#usage" style="color:#29abe2;">Usage</a></li>
    <li><a href="#contact" style="color:#29abe2;">Contact</a></li>
</ul>
<br><br>


<!-- ================= LICENSE SECTION ================= -->
<h1 id="license"align="center" style="color:#40e0d0;">
  LICENSE
</h1>
<h3 align="center" style="color:#29abe2;">
  This project is licensed under the MIT Licence. For details, see the LICENCE file.
</h3>
<br><br>


<!-- ================= INSTALLATION SECTION ================= -->
<h1 id="installation"align="center" style="color:#40e0d0;">
  INSTALLATION
</h1>
<h3 align="center" style="color:#29abe2;">
  To be added later
</h3>
<br>

<!-- ================= INSTALLATION Package SECTION ================= -->
<h2 id="setuppackage" style="color:#40e0d0;">
  With the Package Manager
</h2>
<h3 style="color:#29abe2;">
  To be added later
</h3>
<br>

<!-- ================= INSTALLATION Source SECTION ================= -->
<h2 id="setupsource" style="color:#40e0d0;">
  Compilation from the Source
</h2>
<h3 style="color:#29abe2;">
  To be added later
</h3>
<br><br>


<!-- ================= USAGE SECTION ================= -->
<h1 id="usage"align="center" style="color:#40e0d0;">
  USAGE
</h1>
<h3 align="center" style="color:#29abe2;">
  To be added later
</h3>
<br><br>


<!-- ================= SYNTEX SECTION ================= -->
<h1 id="syntax"align="center" style="color:#40e0d0;">
  SYNTAX
</h1>
<h3 align="center" style="color:#29abe2;">
  To be added later
</h3>
<br>

<!-- ================= SYNTEX Example SECTION ================= -->
<h2 id="syntaxexample" style="color:#40e0d0;">
  Example
</h2>
<br>

```tqs
Use "../others";
Use math;

# comment line

###
comment lines
comment lines
###

Class ClassExample:
    example_str:string="";
    example_int:int=0;
    example_double:double=0.0;
    example_list:list(4)=[];
    example_map:map={};
    private example_private:string="";
    public example_public:string="";

    private function function_example(**args):
        # code blocks
    end

    function function_example(**args):
        if condition:
            # code blocks
        end
        elif condition:
            # code blocks
        end
        elif (condition & condition):
            # code blocks
        end
        else:
            # code blocks
        end

        while condition:
            # code blocks
        end

        for item in list:
            # code blocks
        end
    end

    try:
        # code blocks
    catch error:
        # code blocks
    end

end

private class PrivateClassExample:
    # code blocks
end

GameObject GameObjectExample:
    example_character:Character;
    example_light:Light;
     example_camera:Camera;
     example_barrier:Barrier;
     example_3dmodel:3DMeshModel;
     example_2dmodel:2DMeshModel;
     example_material:Material;
     example_shader:Shader;
     example_animation:Animation;
     example_inputsystem:InputSystem;
     example_actionmap:ActionMap;

    start start_example(**args):
        # code blocks
    end

    update update_example(**args):
        # code blocks
    end

    awake awake_example(**args):
        # code blocks
    end
end

Prefab PrefabExample Inheritance GameObjectExample:
    # code blocks
end

Component ComponentExample:
    example_int:int=100;
    example_int_2=100;

    function example_function(**args):
        # code blocks
    end

    start start_example(**args):
        # code blocks
    end

    update update_example(**args):
        # code blocks
    end
end


```
<br>

<!-- ================= SYNTEX Class SECTION ================= -->
<h2 id="syntaxclass" style="color:#40e0d0;">
  Class
</h2>
<br>

```tqs
  Class ClassExample:
    # code blocks
  end
```
<br>

<!-- ================= SYNTEX Private Class SECTION ================= -->
<h2 id="syntaxprivateclass" style="color:#40e0d0;">
  Private Class
</h2>
<br>

```tqs
  private Class ClassExample:
    # code blocks
  end
```
<br>

<!-- ================= SYNTEX GameObject SECTION ================= -->
<h2 id="syntaxgameo" style="color:#40e0d0;">
  GameObject
</h2>
<br>

```tqs
  GameObject GameObjectExample:
    # code blocks

    # use Special Functions Public or Private
    start start_example(**args):
        # Kod bloğu
    end

    update update_example(**args):
        # Kod bloğu
    end

    awake awake_example(**args):
        # Kod bloğu
    end
  end
```
<br>

<!-- ================= SYNTEX Private GameObject SECTION ================= -->
<h2 id="syntaxprivategameo" style="color:#40e0d0;">
  Private GameObject
</h2>
<br>

```tqs
  private GameObject GameObjectExample:
    # code blocks

    # use Special Functions Public or Private
    private start start_example(**args):
        # Kod bloğu
    end

    private update update_example(**args):
        # Kod bloğu
    end

    private awake awake_example(**args):
        # Kod bloğu
    end
  end
```
<br>

<!-- ================= SYNTEX Prefab SECTION ================= -->
<h2 id="syntaxprefab" style="color:#40e0d0;">
  Prefab
</h2>
<br>

```tqs
  Prefab PrefabExample Inheritance GameObjectExample:
    # Kod bloğu
  end
```
<br>

<!-- ================= SYNTEX Private Prefab SECTION ================= -->
<h2 id="syntaxprivateprefab" style="color:#40e0d0;">
  Private Prefab
</h2>
<br>

```tqs
  private Prefab PrefabExample Inheritance GameObjectExample:
    # Kod bloğu
  end
```
<br>

<!-- ================= SYNTEX Component SECTION ================= -->
<h2 id="syntaxcomponent" style="color:#40e0d0;">
  Component
</h2>
<br>

```tqs
  Component ComponentExample:
    example_int:int=100;
    example_int_2=100;

    function example_function(**args):
        # Kod bloğu
    end

    # use Special Functions Public or Private but except for Awake
    start start_example(**args):
        # Kod bloğu
    end

    update update_example(**args):
        # Kod bloğu
    end
  end
```
<br>

<!-- ================= SYNTEX Private Component SECTION ================= -->
<h2 id="syntaxprivatecomponent" style="color:#40e0d0;">
  Private Component
</h2>
<br>

```tqs
  private Component ComponentExample:
    example_int:int=100;
    example_int_2=100;

    private function example_function(**args):
        # Kod bloğu
    end

    # use Special Functions Public or Private but except for Awake
    private start start_example(**args):
        # Kod bloğu
    end

    private update update_example(**args):
        # Kod bloğu
    end
  end
```
<br>

<!-- ================= SYNTEX Function SECTION ================= -->
<h2 id="syntaxfunction" style="color:#40e0d0;">
  Function
</h2>
<br>

```tqs
  function example_function(**args):
    # Kod bloğu
  end
```
<br>

<!-- ================= SYNTEX Private Function SECTION ================= -->
<h2 id="syntaxprivatefunction" style="color:#40e0d0;">
  Private Function
</h2>
<br>

```tqs
  private function example_function(**args):
    # Kod bloğu
  end
```
<br>

<!-- ================= SYNTEX Variables SECTION ================= -->
<h2 id="syntaxvariables" style="color:#40e0d0;">
  Variables
</h2>
<br>

```tqs
  # String example
  example_str:string="";

  # İnteger example
  example_int:int=0;

  # Double example
  example_double:double=0.0;

  # List example
  example_list:list(4)=[];

  # Map example
  example_map:map={};

  # Private example
  private example_private:string="";

  # Public example
  public example_public:string="";
```
<br>

<!-- ================= SYNTEX Special Variables SECTION ================= -->
<h2 id="syntaxgamevariables" style="color:#40e0d0;">
  GameObject Variables
</h2>
<br>

```tqs
  # Character example
  example_character:character;

  # Light example
  example_light:light;

  # Camera example
  example_camera:camera;

  # Barrier example
  example_barrier:barrier;

  # 3DMeshModel example
  example_3dmodel:3Dmeshmodel;

  # 2DMeshModel example
  example_2dmodel:2Dmeshmodel;

  # Material example
  example_material:material;

  # Shader example
  example_shader:shader;

  # Animation example
  example_animation:animation;

  # InputSystem example
  example_inputsystem:inputsystem;

  # ActionMap example
  example_actionmap:actionmap;
```
<br>
<br><br>

<!-- ================= CONTACT SECTION ================= -->
<h1 id="contact"align="center" style="color:#40e0d0;">
  CONTACT
</h1>
<h3  style="color:#29abe2;">
  For any questions or to discuss the project:
</h3>
<p >

  <p align="center">
  <img src="https://img.shields.io/badge/Developer-Sinan%20Uygun-29abe2">
  <a href="https://github.com/KULLANICIADI">
    <img src="https://img.shields.io/badge/GitHub-Profile-29abe2?logo=github&logoColor=white">
  </a>
  <a href="https://www.linkedin.com/in/KULLANICIADI/">
    <img src="https://img.shields.io/badge/LinkedIn-Profile-29abe2?logo=linkedin&logoColor=white">
  </a>
  <a href="sinanuygunwork@gmail.com">
    <img src="https://img.shields.io/badge/Email-Contact-D14836?logo=gmail&logoColor=white">
  </a>
<br><br>
