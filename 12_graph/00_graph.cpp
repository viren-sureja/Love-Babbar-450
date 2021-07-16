/*
    link: https://youtu.be/LCrovIMurxY?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
    link: https://youtu.be/I6v0itcISSY?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw

    graph is data-structure with 2 component: vertex and edge

    types of graph:
    => there can be multiple paths in the graph

        1. undirected graph:
            -> directonless edge
            -> we can come forth and back from vertex
            -> here degree(vertex) means how many other vertex are connected or edges does it have
            -> total of degrees = 2 * E

        2. directed graph:
            -> with direction edge
            -> we can go from given vertex's direction to
            -> we can write a->b and not b->a if it is directed from a to b
            -> here indegree(vertex) means how many edge are coming towards the vertex,
                    outdegree(vertex) means how many edge are going from vertex to other vertex

        3. undirected cyclic graph:
            contains cycle

        4. directed cyclic graph:
        5. directed acyclic graph

        6. weighted directed graph
        7. weighted undirected graph


    => whenever u see three different island formed in graph
        it's called disconnected graph with multiple component

        for such problem one has to maintain the visited array to checkout all the component
        1. all the vertex of one component will be traversed
        2. then all the vertex of the other component will be traversed

*/