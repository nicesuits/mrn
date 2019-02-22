let component = ReasonReact.statelessComponent("IssueList");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> {ReasonReact.string("Issue Tracker")} </h1>
      <IssueFilter />
      <hr />
      <IssueTable />
      <hr />
      <IssueAdd />
    </div>,
};