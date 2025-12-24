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

