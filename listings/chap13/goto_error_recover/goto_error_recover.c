void foo(void)
{
    if (!doA()) goto exit;
    if (!doB()) goto revertA;
    if (!doC()) goto revertB;

    /* doA, doB and doC succeeded */
    return;

revertB:
    undoB();
revertA:
    undoA();
exit:
    return;
}
