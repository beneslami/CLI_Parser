# CLI_Parser

I have been curious about how Cisco CLI works. Finally, thanks to Coronavirus, I found a time to dig into the question and try to understand what is going on inside Cisco user interface. You definitely have seen what Cisco CLI looks like.

![picture](data/cli.png)

Commands in CLI are implemented as n-aryl Tree. It means every node can have n number of children. So, commands are organized as hierarchy. For example, suppose a command like below:

```
show list [INPUT1] person [INPUT2]
show list all
```

![picture](data/cmd_graph.png)

Each node in the tree is called **param**. Params at the first level of the overall command tree is called **hooks**. Params are categorized into two groups:

1. **command params**: constant keywords in the graph (like show, list, all, person)

2. **leaf params**: denotes to user input in the graph (like INPUT1, INPUT2).
