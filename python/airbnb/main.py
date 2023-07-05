import cmd

class HBNBCommand(cmd.Cmd):
    def do_hola(self, arg):
        print('Hola !!!!')
        arg = arg.split(" ")
        print(arg)
        print(type(arg))

    def do_EOF(self):
        self.close()


if __name__ == '__main__':
    HBNBCommand().cmdloop()
