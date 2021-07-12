/*
    link: https://www.geeksforgeeks.org/chinese-postman-route-inspection-set-1-introduction/

    Algorithm is to find shortest closed path or optimal
    Chinese postman route in a weighted graph that may
    not be Eulerian.

    algo:
    if(eulerian circuit) {
        => return the total weight of whole graph
    }
    else {
        => find all the odd degree vertex
        => for each pairing find shortest path connecting them
        => so, total weight = total weight + total_weight_of_shortest_path_odd_degree_pair;
    }

*/
