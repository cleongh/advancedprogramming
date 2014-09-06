
link(p1, p2).
link(p2, p3).
link(p6, end).
link(p3, p5).
link(p3, p7).
link(p7, p6).
link(p5, p6).
link(p6, end).
link(p3, end).

path([end | P], [end | P]).
path([F | P], Pout) :-
    link(F, O),
    path([O, F | P], Pout).

run :-
    writeln('all paths from p1 to end (reversed):'),
    findall(P, path([p1], P), Pl),
    list_to_set(Pl, Ps),
    maplist(writeln, Ps).

