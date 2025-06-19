### Basic shell commands

-   Show db in shell `show dbs`
-   Use any of the db (ex: practice) `use practice`
-   Create collection: `db.createCollection()`
-   Get collection: `db.getCollection()`
-   Get collection infos: `db.getCollectionInfos()`

### Basic find

-   Find all or based on query : `db.student.find()` or `db.student.find({})`
-   Find one: `db.student.findOne({id: 200041144})`
-   Find with Field Filtering: `db.student.find({gender: "Male"}, {name: {firstName: 1}, gender: 1})`
-   Find with Project: `db.student.find({gender: "Male"}).projection({name: 1, gender: 1})`. Doesn't work for findOne.

### Basic insert

-   Insert One: `db.student.insertOne()`
-   Insert Many: `db.student.insertMany()`

### Operators:

[Query Doc](https://www.mongodb.com/docs/manual/reference/operator/query/)

-   `$eq` : `db.student.find({gender: { $eq: 'Male' }})`
-   Implecit AND: `db.student.find({age: {$gte : 18, $lte: 30}},{age: 1}).sort({age: -1})`, `db.student.find({gender: "Male", age: {$gte : 18, $lte: 30}},{age: 1, gender: 1}).sort({age: -1})`
-   `$in` :

```
    db.student.find(
        {
            gender: "Male",
            age: {$in : [18, 20, 24,26]},
            interests: {$in : ["Cooking", "Reading"]}
        },
        {
            age: 1,
            gender: 1,
            interests: 1
        }
    )
    .sort({age: -1})

```

-   Explicit AND:

```
    db.student.find(
        {
            $and : [
                {age: {$ne : 18}},
                {age: {$lte: 30}},
                {gender: "Male"}
            ]
        }
    )
    .project(
        {gender: 1, age: 1}
    )
```

-   Explicit AND:

```
   db.student.find(
        {
            $or : [
                {"skills.name": "PYTHON"},
                {"skills.name" : "KOTLIN"}
            ],
            gender: "Male"
        }
    )
    .project(
        {gender: 1, age: 1, skills: 1}
    )
    .sort(
        {age: 1}
    )
```

-   `$exists` : `db.student.find({skills: {$exists: false}})` field exists or not.
-   `$type`: `db.student.find({skills : {$type: "Object"}} )`
-   `$size` : `db.student.find({skills : {$size: 0}}, {skills: 1})`
-   `db.student.find({interests : {$all: [ "Cooking", "Writing", "Reading" ]}}, {interests: 1})`
-   Element match both for query and projection:

```
db.student.find({
    skills: {$elemMatch: {name: 'JAVASCRIPT', level:"Beginner"}}
}, {skills: {$elemMatch: {name: 'JAVASCRIPT', level:"Beginner"}}})
```
