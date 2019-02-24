let component = ReasonReact.statelessComponent("IssueList");

let issuesData: list(IssueType.issue) = [
  {
    id: 1,
    status: "Open",
    owner: "Ravan",
    created: "2016-08-15",
    effort: 5,
    completedDate: "undefined",
    title: "Error in console when clicking Add",
  },
  {
    id: 2,
    status: "Assigned",
    owner: "Eddie",
    created: "2016-08-16",
    effort: 14,
    completedDate: "2016-08-30",
    title: "Missing bottom border on panel",
  },
];

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> {ReasonReact.string("Issue Tracker")} </h1>
      <IssueFilter />
      <hr />
      <IssueTable issues=issuesData />
      <hr />
      <IssueAdd />
    </div>,
};