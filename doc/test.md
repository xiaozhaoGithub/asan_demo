# 测试过程

## 启动程序

- 设置asan选项

```shell
export ASAN_OPTIONS=halt_on_error=0:detect_leaks=1:malloc_context_size=15:detect_stack_use_after_return=1:log_path=./asan.log
```

* 运行程序

  ``` shell
  ./asan_demo
  ```

- 查看日志输出

  ``` shell
  # 日志名称为测试环境下的文件
  cat asan.log.xxx
  ```

## 分析结果

### stack-overflow

递归调用函数，无退出条件，栈空间不足，导致栈溢出

``` shell
=================================================================
==305763==ERROR: AddressSanitizer: stack-overflow on address 0x7fffea94aff8 (pc 0x55e2d47e0d33 bp 0x7fffea94b020 sp 0x7fffea94b000 T0)
    #0 0x55e2d47e0d32 in std::__detail::_Hash_code_base<unsigned int, std::pair<unsigned int const, std::shared_ptr<AbstractBug> >, std::__detail::_Select1st, std::hash<unsigned int>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, false>::_M_bucket_index(unsigned int const&, unsigned long, unsigned long) const (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x4d32)
    #1 0x55e2d47e022f in std::_Hashtable<unsigned int, std::pair<unsigned int const, std::shared_ptr<AbstractBug> >, std::allocator<std::pair<unsigned int const, std::shared_ptr<AbstractBug> > >, std::__detail::_Select1st, std::equal_to<unsigned int>, std::hash<unsigned int>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<false, false, true> >::_M_bucket_index(unsigned int const&, unsigned long) const (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x422f)
    #2 0x55e2d47df6a6 in std::_Hashtable<unsigned int, std::pair<unsigned int const, std::shared_ptr<AbstractBug> >, std::allocator<std::pair<unsigned int const, std::shared_ptr<AbstractBug> > >, std::__detail::_Select1st, std::equal_to<unsigned int>, std::hash<unsigned int>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<false, false, true> >::find(unsigned int const&) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x36a6)
    #3 0x55e2d47def4a in std::unordered_map<unsigned int, std::shared_ptr<AbstractBug>, std::hash<unsigned int>, std::equal_to<unsigned int>, std::allocator<std::pair<unsigned int const, std::shared_ptr<AbstractBug> > > >::find(unsigned int const&) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x2f4a)
    #4 0x55e2d47de685 in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x2685)
    #5 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #6 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #7 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #8 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #9 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #10 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #11 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #12 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #13 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #14 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #15 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #16 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #17 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #18 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #19 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #20 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #21 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #22 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #23 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #24 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #25 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #26 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #27 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #28 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #29 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #30 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #31 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #32 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #33 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #34 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #35 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #36 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #37 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #38 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #39 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #40 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #41 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #42 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #43 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #44 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #45 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #46 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #47 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #48 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #49 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #50 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #51 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #52 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #53 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #54 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #55 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #56 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #57 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #58 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #59 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #60 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #61 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #62 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #63 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #64 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #65 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #66 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #67 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #68 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #69 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #70 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #71 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #72 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #73 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #74 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #75 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #76 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #77 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #78 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #79 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #80 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #81 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #82 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #83 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #84 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #85 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #86 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #87 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #88 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #89 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #90 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #91 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #92 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #93 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #94 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #95 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #96 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #97 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #98 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #99 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #100 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #101 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #102 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #103 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #104 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #105 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #106 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #107 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #108 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #109 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #110 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #111 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #112 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #113 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #114 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #115 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #116 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #117 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #118 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #119 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #120 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #121 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #122 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #123 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #124 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #125 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #126 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #127 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #128 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #129 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #130 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #131 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #132 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #133 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #134 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #135 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #136 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #137 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #138 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #139 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #140 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #141 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #142 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #143 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #144 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #145 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #146 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #147 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #148 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #149 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #150 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #151 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #152 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #153 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #154 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #155 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #156 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #157 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #158 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #159 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #160 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #161 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #162 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #163 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #164 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #165 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #166 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #167 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #168 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #169 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #170 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #171 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #172 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #173 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #174 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #175 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #176 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #177 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #178 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #179 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #180 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #181 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #182 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #183 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #184 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #185 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #186 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #187 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #188 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #189 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #190 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #191 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #192 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #193 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #194 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #195 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #196 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #197 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #198 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #199 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #200 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #201 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #202 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #203 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #204 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #205 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #206 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #207 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #208 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #209 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #210 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #211 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #212 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #213 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #214 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #215 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #216 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #217 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #218 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #219 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #220 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #221 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #222 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #223 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #224 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #225 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #226 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #227 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #228 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #229 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #230 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #231 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #232 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #233 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #234 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #235 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #236 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #237 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #238 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #239 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #240 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #241 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #242 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #243 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #244 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #245 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #246 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #247 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #248 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #249 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)
    #250 0x55e2d47de6eb in BugFactory::GetBug(unsigned int) (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x26eb)

SUMMARY: AddressSanitizer: stack-overflow (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x4d32) in std::__detail::_Hash_code_base<unsigned int, std::pair<unsigned int const, std::shared_ptr<AbstractBug> >, std::__detail::_Select1st, std::hash<unsigned int>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, false>::_M_bucket_index(unsigned int const&, unsigned long, unsigned long) const
==305763==ABORTING

```

### heap-buffer-overflow

先分配32字节后，在heap_buf的第30个字节开始，拷贝8个字符

``` shell
root@coder-develop:/home/coder/workspace/github_code/asan_demo/build# cat asan.log.306182
=================================================================
==306182==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x603000000090 at pc 0x7f2a1ed4558a bp 0x7ffec17fc4b0 sp 0x7ffec17fbc58
WRITE of size 8 at 0x603000000090 thread T0
    #0 0x7f2a1ed45589  (/lib/x86_64-linux-gnu/libasan.so.4+0x7a589)
    #1 0x55ea549248eb in HeapBufferOverflowBug::DoWork() (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x98eb)
    #2 0x55ea5491d37b in main (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x237b)
    #3 0x7f2a1e900082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)
    #4 0x55ea5491d18d in _start (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x218d)

0x603000000090 is located 0 bytes to the right of 32-byte region [0x603000000070,0x603000000090)
allocated by thread T0 here:
    #0 0x7f2a1edaa950 in __interceptor_malloc (/lib/x86_64-linux-gnu/libasan.so.4+0xdf950)
    #1 0x55ea549248cb in HeapBufferOverflowBug::DoWork() (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x98cb)
    #2 0x55ea5491d37b in main (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x237b)
    #3 0x7f2a1e900082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)

SUMMARY: AddressSanitizer: heap-buffer-overflow (/lib/x86_64-linux-gnu/libasan.so.4+0x7a589)
Shadow bytes around the buggy address:
  0x0c067fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff8000: fa fa 00 00 00 fa fa fa 00 00 00 00 fa fa 00 00
=>0x0c067fff8010: 00 00[fa]fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8060: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
```

### stack-buffer-overflow

默认拷贝5字节到4字节的数组，包括字符串默认'\0'

```shell
root@coder-develop:/home/coder/workspace/github_code/asan_demo/build# cat asan.log.312889
=================================================================
==312889==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7f4e4ff003e4 at pc 0x7f4e53ae358a bp 0x7ffd804781c0 sp 0x7ffd80477968
WRITE of size 5 at 0x7f4e4ff003e4 thread T0
    #0 0x7f4e53ae3589  (/lib/x86_64-linux-gnu/libasan.so.4+0x7a589)
    #1 0x5641b27f4be3 in StackBufferOverflowBug::DoWork() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:29
    #2 0x5641b27e65e7 in main /home/coder/workspace/github_code/asan_demo/src/main.cpp:21
    #3 0x7f4e5369e082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)
    #4 0x5641b27e62ad in _start (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x32ad)

Address 0x7f4e4ff003e4 is located in stack of thread T0 at offset 36 in frame
    #0 0x5641b27f4b1d in StackBufferOverflowBug::DoWork() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:26

  This frame has 1 object(s):
    [32, 36) 'stack_buf' <== Memory access at offset 36 overflows this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism or swapcontext
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow (/lib/x86_64-linux-gnu/libasan.so.4+0x7a589)
Shadow bytes around the buggy address:
  0x0fea49fd8020: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x0fea49fd8030: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x0fea49fd8040: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x0fea49fd8050: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x0fea49fd8060: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
=>0x0fea49fd8070: f5 f5 f5 f5 f5 f5 f5 f5 f1 f1 f1 f1[04]f2 f2 f2
  0x0fea49fd8080: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0fea49fd8090: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0fea49fd80a0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0fea49fd80b0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0fea49fd80c0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
```

### heap-use-after-free

使用释放后的指针

```shell
root@coder-develop:/home/coder/workspace/github_code/asan_demo/build# cat asan.log.312680
=================================================================
==312680==ERROR: AddressSanitizer: heap-use-after-free on address 0x603000000070 at pc 0x55e00e05ccb8 bp 0x7ffd91d52c20 sp 0x7ffd91d52c10
READ of size 1 at 0x603000000070 thread T0
    #0 0x55e00e05ccb7 in HeapUseAfterFreeBug::DoWork() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:38
    #1 0x55e00e04e5e7 in main /home/coder/workspace/github_code/asan_demo/src/main.cpp:21
    #2 0x7f43b1c96082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)
    #3 0x55e00e04e2ad in _start (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x32ad)

0x603000000070 is located 0 bytes inside of 32-byte region [0x603000000070,0x603000000090)
freed by thread T0 here:
    #0 0x7f43b21405b8 in __interceptor_free (/lib/x86_64-linux-gnu/libasan.so.4+0xdf5b8)
    #1 0x55e00e05cc83 in HeapUseAfterFreeBug::DoWork() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:36
    #2 0x55e00e04e5e7 in main /home/coder/workspace/github_code/asan_demo/src/main.cpp:21
    #3 0x7f43b1c96082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)

previously allocated by thread T0 here:
    #0 0x7f43b2140950 in __interceptor_malloc (/lib/x86_64-linux-gnu/libasan.so.4+0xdf950)
    #1 0x55e00e05cc73 in HeapUseAfterFreeBug::DoWork() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:35
    #2 0x55e00e04e5e7 in main /home/coder/workspace/github_code/asan_demo/src/main.cpp:21
    #3 0x7f43b1c96082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)

SUMMARY: AddressSanitizer: heap-use-after-free /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:38 in HeapUseAfterFreeBug::DoWork()
Shadow bytes around the buggy address:
  0x0c067fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c067fff8000: fa fa 00 00 00 00 fa fa 00 00 00 00 fa fa[fd]fd
  0x0c067fff8010: fd fd fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==312680==ABORTING
```

### stack-use-after-return

访问已释放的栈地址内存

```shell
root@coder-develop:/home/coder/workspace/github_code/asan_demo/build# cat asan.log.312973
=================================================================
==312973==ERROR: AddressSanitizer: stack-use-after-return on address 0x7fb00b200024 at pc 0x561048c60cf0 bp 0x7fffc8981be0 sp 0x7fffc8981bd0
READ of size 4 at 0x7fb00b200024 thread T0
    #0 0x561048c60cef in StackUseAfterReturnBug::DoWork() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:46
    #1 0x561048c525e7 in main /home/coder/workspace/github_code/asan_demo/src/main.cpp:21
    #2 0x7fb00e80f082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)
    #3 0x561048c522ad in _start (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x32ad)

Address 0x7fb00b200024 is located in stack of thread T0 at offset 36 in frame
    #0 0x561048c60d07 in StackUseAfterReturnBug::CreateStackPointer() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:50

  This frame has 1 object(s):
    [32, 72) 'local' <== Memory access at offset 36 is inside this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism or swapcontext
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-use-after-return /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:46 in StackUseAfterReturnBug::DoWork()
Shadow bytes around the buggy address:
  0x0ff681637fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff681637fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff681637fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff681637fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff681637ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0ff681638000: f5 f5 f5 f5[f5]f5 f5 f5 f5 f5 f5 f5 00 00 00 00
  0x0ff681638010: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff681638020: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff681638030: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff681638040: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff681638050: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==312973==ABORTING
```

### stack-use-after-scope

访问离开作用域已被释放的变量

```shell
root@coder-develop:/home/coder/workspace/github_code/asan_demo/build# cat asan.log.313128
=================================================================
==313128==ERROR: AddressSanitizer: stack-use-after-scope on address 0x7f9e39b003e0 at pc 0x55a03021301b bp 0x7ffd95a90b20 sp 0x7ffd95a90b10
READ of size 4 at 0x7f9e39b003e0 thread T0
    #0 0x55a03021301a in StackUseAfterScopeBug::DoWork() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:67
    #1 0x55a0302045e7 in main /home/coder/workspace/github_code/asan_demo/src/main.cpp:21
    #2 0x7f9e3d1d5082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)
    #3 0x55a0302042ad in _start (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x32ad)

Address 0x7f9e39b003e0 is located in stack of thread T0 at offset 32 in frame
    #0 0x55a030212f15 in StackUseAfterScopeBug::DoWork() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:59

  This frame has 1 object(s):
    [32, 36) 'val' <== Memory access at offset 32 is inside this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism or swapcontext
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-use-after-scope /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:67 in StackUseAfterScopeBug::DoWork()
Shadow bytes around the buggy address:
  0x0ff447358020: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x0ff447358030: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x0ff447358040: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x0ff447358050: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x0ff447358060: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
=>0x0ff447358070: f5 f5 f5 f5 f5 f5 f5 f5 f1 f1 f1 f1[f8]f2 f2 f2
  0x0ff447358080: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff447358090: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff4473580a0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff4473580b0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0ff4473580c0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==313128==ABORTING
```

### double-free

重复释放同一指针

```shell
root@coder-develop:/home/coder/workspace/github_code/asan_demo/build# cat asan.log.308566
=================================================================
==308566==ERROR: AddressSanitizer: attempting double-free on 0x603000000070 in thread T0:
    #0 0x7fa7a68135b8 in __interceptor_free (/lib/x86_64-linux-gnu/libasan.so.4+0xdf5b8)
    #1 0x5565db95b619 in DoubleFreeBug::DoWork() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:75
    #2 0x5565db95337b in main /home/coder/workspace/github_code/asan_demo/src/main.cpp:21
    #3 0x7fa7a6369082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)
    #4 0x5565db95318d in _start (/home/coder/workspace/github_code/asan_demo/build/asan_demo+0x218d)

0x603000000070 is located 0 bytes inside of 32-byte region [0x603000000070,0x603000000090)
freed by thread T0 here:
    #0 0x7fa7a68135b8 in __interceptor_free (/lib/x86_64-linux-gnu/libasan.so.4+0xdf5b8)
    #1 0x5565db95b60d in DoubleFreeBug::DoWork() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:74
    #2 0x5565db95337b in main /home/coder/workspace/github_code/asan_demo/src/main.cpp:21
    #3 0x7fa7a6369082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)

previously allocated by thread T0 here:
    #0 0x7fa7a6813950 in __interceptor_malloc (/lib/x86_64-linux-gnu/libasan.so.4+0xdf950)
    #1 0x5565db95b5fd in DoubleFreeBug::DoWork() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:73
    #2 0x5565db95337b in main /home/coder/workspace/github_code/asan_demo/src/main.cpp:21
    #3 0x7fa7a6369082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)

SUMMARY: AddressSanitizer: double-free (/lib/x86_64-linux-gnu/libasan.so.4+0xdf5b8) in __interceptor_free
```

### memory leaks

申请 40字节未释放，导致内存泄漏

注：特别说明，当程序正在运行时，发生内存泄漏，程序未停止，asan不认为它是内存泄漏。这种情况通过堆分析对比，查看持续增长的内存函数。

```shell
root@coder-develop:/home/coder/workspace/github_code/asan_demo/build# cat asan.log.308687

=================================================================
==308687==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 40 byte(s) in 10 object(s) allocated from:
    #0 0x7f847329a258 in operator new(unsigned long) (/lib/x86_64-linux-gnu/libasan.so.4+0xe1258)
    #1 0x55ba5c11c665 in MemoryLeaksBug::AllocBuffer() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:91
    #2 0x55ba5c11c642 in MemoryLeaksBug::DoWork() /home/coder/workspace/github_code/asan_demo/src/bugs.cpp:82
    #3 0x55ba5c11437b in main /home/coder/workspace/github_code/asan_demo/src/main.cpp:21
    #4 0x7f8472dee082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)

SUMMARY: AddressSanitizer: 40 byte(s) leaked in 10 allocation(s).
```

## 分析工具

### addr2line

若无符号文件，可结合addr2line工具将出错地址转文件行号输出

```shell
# addr2line -C -f -e asan_demo 0x...
```

# TODO

其他测试案例待研究
