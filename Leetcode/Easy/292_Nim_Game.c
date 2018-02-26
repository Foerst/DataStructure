bool canWinNim(int n) {
    // 如果一开始就是4的倍数，你就输了，因为对方可以用同样的策略
    return n % 4 != 0;
}
