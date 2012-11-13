
dst = read.matrix("all_pairs0.dat")
mds = cmdscale(dst, k=2)
plot(mds)
write.table(mds, file="points.dat", row.names=FALSE, col.names=FALSE)

