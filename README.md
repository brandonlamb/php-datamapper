
What is this?
=============

This is an attempt at a mashup of some pieces of phalconphp, pdm, spot and probably a few other ORMs.

## Design thoughts/intentions

- Simplify! Need an ORM with a query builder that solves the 80% rule

- Need to support mysql, postgresql and db2 (my needs at least)

- Reduce "bloat" - Totally an opinion, but I find migration code to be "bloat". I prefer not having this in an ORM and use other tools

- Reduce "bloat" - Remove support for "relationships", mostly just based on my experience that the automagic stuff ends up needing to be manually handled anyway for performance

- Support for composite keys. My work has some old, crappy design legacy tables with say 5 column composite keys.

- Support for identify columns/sequences

- Keep meta data config simple, just use basic arrays. No fancy parsing for yaml, annotations, etc.

- Data mapper to handle entity/model classes. Love the spot (and probably doctrine) way of $mapper->save($entity)

## Misc

- Conform to PSR standards

- No snake case variables/methods - Ns\ClassName::methodName(variableName)
