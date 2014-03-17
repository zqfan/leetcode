#! /usr/bin/env python

import argparse
import importlib
import inspect
import json
import sys

def run_unittest(problem):
    # load the solution
    module = importlib.import_module(problem)
    solution = getattr(module, 'Solution', None)

    # find the target method, there should be one and only one method, which
    # does not start with underscore('_')
    funcs = inspect.getmembers(solution(), inspect.ismethod)
    pub_funcs = filter(lambda x: not x[0].startswith('_'), funcs)
    func = pub_funcs[0][1]

    # load all the test data
    test_data = _load_data('tests/data/%s.test' % problem)
    expected_result = _load_data('tests/data/%s.result' % problem)

    # run each test data
    fail = 0
    for i in range(len(test_data)):
        result = func(test_data[i])
        if result != expected_result[i]:
            print ('Error:\ntest data = %s\nexpects = %s\ngot = %s'
                   % (test_data[i], expected_result[i], result))
            fail += 1

    print 'Success!' if not fail else '%d failed' % fail

def _load_data(filename):
    with open(filename) as f:
        lines = map(lambda x: x.strip(), f.readlines())
        lines = filter(lambda x: not x.startswith('#'), lines)
        return map(lambda x: json.loads(x), lines)

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('name', metavar='problem-name')
    args = ap.parse_args(sys.argv[1:])
    run_unittest(args.name)

if __name__ == '__main__':
    main()
