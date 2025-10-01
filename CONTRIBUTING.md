# Contributing to AlgoVault

We love your input! We want to make contributing to AlgoVault as easy and transparent as possible, whether it's:

- Reporting a bug
- Discussing the current state of the code
- Submitting a fix
- Proposing new features
- Becoming a maintainer

## Development Process

We use GitHub to host code, to track issues and feature requests, as well as accept pull requests.

## Pull Requests

Pull requests are the best way to propose changes to the codebase. We actively welcome your pull requests:

1. Fork the repo and create your branch from `main`.
2. If you've added code that should be tested, add tests.
3. If you've changed APIs, update the documentation.
4. Ensure the test suite passes.
5. Make sure your code lints.
6. Issue that pull request!

## Adding New Algorithms

### For Sorting Algorithms:

1. **Add to `sorting.h`**:
   ```cpp
   static void newSortAlgorithm(std::vector<int>& arr);
   static void newSortAlgorithmVisualized(std::vector<int>& arr);
   ```

2. **Implement in `sorting.cpp`**:
   - Follow the existing pattern with step-by-step visualization
   - Include complexity analysis
   - Add comprehensive comments

3. **Update menu system** in `showSortingMenu()` and `runSortingAlgorithms()`

### For Graph Algorithms:

1. **Add to `graph.h`**:
   ```cpp
   void newGraphAlgorithm(int startVertex);
   ```

2. **Implement in `graph.cpp`**:
   - Follow existing visualization patterns
   - Include step-by-step output
   - Add complexity information

3. **Update menu system** in graph algorithm functions

## Coding Style

- Use consistent indentation (4 spaces)
- Follow existing naming conventions
- Add comments for complex algorithms
- Include visualization steps for educational value
- Maintain the modular structure

## Bug Reports

We use GitHub issues to track public bugs. Report a bug by opening a new issue.

**Great Bug Reports** tend to have:

- A quick summary and/or background
- Steps to reproduce
  - Be specific!
  - Give sample code if you can
- What you expected would happen
- What actually happens
- Notes (possibly including why you think this might be happening, or stuff you tried that didn't work)

## Feature Requests

We welcome feature requests! Please provide:

- Clear description of the feature
- Why it would be useful
- Example use cases
- Potential implementation approach (if you have ideas)

## License

By contributing, you agree that your contributions will be licensed under its MIT License.

## Questions?

Feel free to contact us if you have any questions about contributing!